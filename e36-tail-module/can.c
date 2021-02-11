/*
 * CAN messaging
 *
 */

#include <mscan.h>
#include <timer.h>

#include "defs.h"

static CAN_message msg_buf;

void
can_listen(struct pt *pt)
{
    static timer_t  can_idle_timer = { .delay_ms = 500 };
    pt_begin(pt);

    while (pt_running(pt)) {
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
                timer_reset(can_idle_timer, 500);
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
        }
    }
    pt_end(pt);
}

void
can_report(struct pt *pt)
{
    static volatile timer_t can_report_timer = { .delay_ms = 100 };
    static uint8_t live_counter;

    pt_begin(pt);
    timer_register(&can_report_timer);
    monitor_init();

    while (pt_running(pt)) {
        pt_wait(pt, timer_expired(can_report_timer));

        // Status report message (custom)
        //
        uint16_t fuel_mv = monitor_get(MON_FUEL_LEVEL);

        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00000);
        msg_buf.dlc = 8;
        msg_buf.data[0] = fuel_mv & 0xff;
        msg_buf.data[1] = fuel_mv >> 8;
        msg_buf.data[2] = fault_system.raw;
        msg_buf.data[3] = fault_output[0].raw;
        msg_buf.data[4] = fault_output[1].raw;
        msg_buf.data[5] = fault_output[2].raw;
        msg_buf.data[6] = fault_output[3].raw;
        msg_buf.data[7] = live_counter++;
        CAN_send_blocking(&msg_buf);

        // Debug message
        //

        uint16_t kl15_mv = monitor_get(MON_KL15);
        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00001);
        msg_buf.dlc = 8;
        msg_buf.data[0] = kl15_mv & 0xff;
        msg_buf.data[1] = kl15_mv >> 8;
        msg_buf.data[2] = 0;
        msg_buf.data[3] = 0;
        msg_buf.data[4] = 0;
        msg_buf.data[5] = 0;
        msg_buf.data[6] = 0;
        msg_buf.data[7] = live_counter++;
        CAN_send_blocking(&msg_buf);

        timer_reset(can_report_timer, 500);
    }
    pt_end(pt);
}