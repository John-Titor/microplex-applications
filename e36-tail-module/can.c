/*
 * CAN messaging
 */

#include <timer.h>

#include "defs.h"

static CAN_message_t msg_buf;

unsigned can_rx_count;

void
can_listen(struct pt *pt)
{
    static timer_t  can_idle_timer = { .delay_ms = CAN_IDLE_TIMEOUT };

    pt_begin(pt);
    timer_register(&can_idle_timer);

    for (;;) {

        // check for a CAN message
        if (CAN_recv(&msg_buf)) {

            // we're hearing CAN, so reset the idle timer / fault
            timer_reset(can_idle_timer, CAN_IDLE_TIMEOUT);
            fault_clear_system(SYS_FAULT_CAN_TIMEOUT);
            can_rx_count++;


            // BMW brake pedal message
            //
            if (MSCAN_ID_MATCH(0xa8, msg_buf) && (msg_buf.dlc == 8)) {
                brake_light_request((msg_buf.data[7] > 20) ? LIGHT_ON : LIGHT_OFF);
            }

            // BMW lighting message
            //
            else if (MSCAN_ID_MATCH(0x21a, msg_buf) && (msg_buf.dlc == 3)) {
                tail_light_request((msg_buf.data[0] & 0x04) ? LIGHT_ON : LIGHT_OFF);
                rain_light_request((msg_buf.data[0] & 0x40) ? LIGHT_ON : LIGHT_OFF);
            }

            // EDIABAS-style request
            else if (MSCAN_ID_MATCH(0x6f1, msg_buf) && (msg_buf.dlc == 8)) {
                cas_jbe_recv(NULL);
            }
        }

        // if we haven't heard a useful CAN message for a while...
        if (timer_expired(can_idle_timer)) {
            fault_set_system(SYS_FAULT_CAN_TIMEOUT);
            brake_light_request(LIGHT_FAULT);
        }

        pt_yield(pt);
    }
    pt_end(pt);
}

void
can_report_fuel(struct pt *pt)
{
    static volatile timer_t can_report_fuel_timer = {
        .delay_ms = CAN_REPORT_INTERVAL_FUEL
    };
    static uint8_t live_counter;

    pt_begin(pt);
    timer_register(&can_report_fuel_timer);

    for (;;) {
        uint16_t mon_val;
        pt_wait(pt, timer_expired(can_report_fuel_timer));

        // send BMW fuel level message
        msg_buf.id.mscan_id = MSCAN_ID(0x349);
        msg_buf.dlc = 5;
        mon_val = monitor_get(MON_FUEL_LEVEL) * 6; // approximate scale 0-0x8000
        msg_buf.data[0] = mon_val & 0xff;
        msg_buf.data[1] = mon_val >> 8;
        msg_buf.data[2] = mon_val & 0xff;
        msg_buf.data[3] = mon_val >> 8;
        msg_buf.data[4] = 0;

        CAN_send_blocking(&msg_buf);
        pt_yield(pt);


        timer_reset(can_report_fuel_timer, CAN_REPORT_INTERVAL_FUEL);
    }
    pt_end(pt);
}

void
can_report_diags(struct pt *pt)
{
    static volatile timer_t can_report_diags_timer = {
        .delay_ms = CAN_REPORT_INTERVAL_DIAGS
    };
    static uint8_t live_counter;

    pt_begin(pt);
    timer_register(&can_report_diags_timer);

    for (;;) {
        pt_delay(pt, can_report_diags_timer, CAN_REPORT_INTERVAL_DIAGS);
        
#if (CAN_REPORT_INTERVAL_DIAGS > 0)
        uint16_t mon_val;

        msg_buf.id.mscan_id = MSCAN_ID_EXT(0x0f00000);
        msg_buf.dlc = 8;
        msg_buf.data[0] = 0;
        msg_buf.data[1] = 0;
        mon_val = monitor_get(MON_T15_VOLTAGE);
        msg_buf.data[2] = mon_val >> 8;
        msg_buf.data[3] = mon_val & 0xff;
        mon_val = monitor_get(MON_TEMPERATURE);
        if (mon_val < 1396) {
            // not interesting
            mon_val = 0;
        } else {
            mon_val -= 1396;    // Vtemp25
            mon_val *= 275;     // scale to mC°
            mon_val /= 1000;    // back to C°
            mon_val += 25;      // offset
        }
        msg_buf.data[4] = mon_val;
        mon_val = monitor_get(MON_FUEL_LEVEL);
        msg_buf.data[5] = mon_val / 50; // scale 0-5000 -> %
        msg_buf.data[6] = output_state_requested;
        msg_buf.data[7] = ((brake_light_requested ? 1 : 0) | 
                           (tail_light_requested ? 2 : 0) |
                           (rain_light_requested ? 4 : 0));
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        msg_buf.id.mscan_id = MSCAN_ID_EXT(0x0f00001);
        msg_buf.dlc = 8;
        mon_val = monitor_get(MON_OUT_V_1);
        msg_buf.data[0] = mon_val / 100;
        mon_val = monitor_get(MON_OUT_V_2);
        msg_buf.data[1] = mon_val / 100;
        mon_val = monitor_get(MON_OUT_V_3);
        msg_buf.data[2] = mon_val / 100;
        mon_val = monitor_get(MON_OUT_V_4);
        msg_buf.data[3] = mon_val / 100;
        mon_val = monitor_get(MON_OUT_I_1);
        msg_buf.data[4] = mon_val / 10;
        mon_val = monitor_get(MON_OUT_I_2);
        msg_buf.data[5] = mon_val / 10;
        mon_val = monitor_get(MON_OUT_I_3);
        msg_buf.data[6] = mon_val / 10;
        mon_val = monitor_get(MON_OUT_I_4);
        msg_buf.data[7] = mon_val / 10;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        msg_buf.id.mscan_id = MSCAN_ID_EXT(0x0f00002);
        msg_buf.dlc = 8;
        msg_buf.data[0] = fault_output[0].raw;
        msg_buf.data[1] = fault_output[1].raw;
        msg_buf.data[2] = fault_output[2].raw;
        msg_buf.data[3] = fault_output[3].raw;
        msg_buf.data[4] = 0x11;
        msg_buf.data[5] = 0x22;
        msg_buf.data[6] = 0x33;
        msg_buf.data[7] = fault_system.raw;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);
#endif // (CAN_REPORT_INTERVAL_DIAGS > 0)
    }
    pt_end(pt);
}
