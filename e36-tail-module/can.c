/*
 * CAN messaging
 */

#include <mscan.h>
#include <timer.h>

#include "defs.h"

#define CAN_IDLE_TIMEOUT    500
#define CAN_REPORT_INTERVAL 500

static CAN_message msg_buf;

void
can_listen(struct pt *pt)
{
    static timer_t  can_idle_timer = { .delay_ms = CAN_IDLE_TIMEOUT };

    pt_begin(pt);
    timer_register(&can_idle_timer);

    for (;;) {
        pt_wait(pt, CAN_recv(&msg_buf) || timer_expired(can_idle_timer));

        switch (msg_buf.id.mscan_id) {

        // Brake lights on/of, sent from the DDE
        //
        // http://www.loopybunny.co.uk/CarPC/can/0A8.html
        //
        // XXX need some sort of story around missing-message timeouts
        case MSCAN_ID(0xa8):
            if (msg_buf.dlc == 8) {

                // we're hearing CAN, so clear the fault and reset the timer
                timer_reset(can_idle_timer, CAN_IDLE_TIMEOUT);
                fault_clear_system(SYS_FAULT_CAN_TIMEOUT);

                // turn brake lights on / off as requested
                output_request(OUTPUT_BRAKE_L, msg_buf.data[7] > 20);
                output_request(OUTPUT_BRAKE_R, msg_buf.data[7] > 20);
            }
            break;
        }

        // if we haven't heard a useful CAN message for a while...
        if (timer_expired(can_idle_timer)) {
            fault_set_system(SYS_FAULT_CAN_TIMEOUT);
            timer_reset(can_idle_timer, CAN_IDLE_TIMEOUT);
        }
    }
    pt_end(pt);
}

void
can_report(struct pt *pt)
{
    static volatile timer_t can_report_timer = { .delay_ms = CAN_REPORT_INTERVAL };
    static uint8_t live_counter;

    pt_begin(pt);
    timer_register(&can_report_timer);

    for (;;) {
        uint16_t mon_val;
        pt_wait(pt, timer_expired(can_report_timer));

        // Status report message (custom)
        //
        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00000);
        msg_buf.dlc = 8;
        mon_val = monitor_get(MON_FUEL_LEVEL);
        msg_buf.data[0] = mon_val & 0xff;
        msg_buf.data[1] = mon_val >> 8;
        msg_buf.data[2] = fault_system.raw;
        msg_buf.data[3] = fault_output[0].raw;
        msg_buf.data[4] = fault_output[1].raw;
        msg_buf.data[5] = fault_output[2].raw;
        msg_buf.data[6] = fault_output[3].raw;
        msg_buf.data[7] = live_counter++;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        // Debug messages
        //
        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00001);
        msg_buf.dlc = 8;
        mon_val = monitor_get(MON_KL15);
        msg_buf.data[0] = mon_val & 0xff;
        msg_buf.data[1] = mon_val >> 8;
        msg_buf.data[2] = 0;
        msg_buf.data[3] = 0;
        msg_buf.data[4] = 0;
        msg_buf.data[5] = 0;
        msg_buf.data[6] = 0;
        msg_buf.data[7] = live_counter++;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00002);
        msg_buf.dlc = 8;
        mon_val = monitor_get(MON_OUT_V_1);
        msg_buf.data[0] = mon_val & 0xff;
        msg_buf.data[1] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_V_2);
        msg_buf.data[2] = mon_val & 0xff;
        msg_buf.data[3] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_V_3);
        msg_buf.data[4] = mon_val & 0xff;
        msg_buf.data[5] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_V_4);
        msg_buf.data[6] = mon_val & 0xff;
        msg_buf.data[7] = mon_val >> 8;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00003);
        msg_buf.dlc = 8;
        mon_val = monitor_get(MON_OUT_I_1);
        msg_buf.data[0] = mon_val & 0xff;
        msg_buf.data[1] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_I_2);
        msg_buf.data[2] = mon_val & 0xff;
        msg_buf.data[3] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_I_3);
        msg_buf.data[4] = mon_val & 0xff;
        msg_buf.data[5] = mon_val >> 8;
        mon_val = monitor_get(MON_OUT_I_4);
        msg_buf.data[6] = mon_val & 0xff;
        msg_buf.data[7] = mon_val >> 8;
        CAN_send_blocking(&msg_buf);
        pt_yield(pt);

        timer_reset(can_report_timer, CAN_REPORT_INTERVAL);
    }
    pt_end(pt);
}
