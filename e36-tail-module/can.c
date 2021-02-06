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
    pt_begin(pt);

    while (pt_running(pt)) {
        pt_wait(pt, CAN_recv(&msg_buf));

        switch (msg_buf.id.mscan_id) {

        // Brake lights on/of, sent from the DDE
        //
        // http://www.loopybunny.co.uk/CarPC/can/0A8.html
        //
        // XXX need some sort of story around missing-message timeouts
        case MSCAN_ID(0xa8):
            if (msg_buf.dlc == 8) {
                output_request(OUTPUT_BRAKE_L, msg_buf.data[7] > 20);
                output_request(OUTPUT_BRAKE_R, msg_buf.data[7] > 20);
            }
            break;
        }
    }
    pt_end(pt);
}

void
can_report(struct pt *pt)
{
    static volatile timer_t can_report_timer = { .delay_ms = 100 };

    pt_begin(pt);
    timer_register(&can_report_timer);
    monitor_init();

    while (pt_running(pt)) {
        pt_wait(pt, timer_expired(can_report_timer));

        // Status report message (custom)
        //
        // bytes 0,1 are fuel level in mV
        // bytes 2-5 are output status
        //
        uint16_t fuel_mv = monitor_get(MON_FUEL_LEVEL);

        msg_buf.id.mscan_id = MSCAN_ID_EXTENDED(0x0f00000);
        msg_buf.dlc = 9;
        msg_buf.data[0] = fuel_mv & 0xff;
        msg_buf.data[1] = fuel_mv >> 8;
        msg_buf.data[2] = output_status(0);
        msg_buf.data[3] = output_status(1);
        msg_buf.data[4] = output_status(2);
        msg_buf.data[5] = output_status(3);
        msg_buf.data[6] = 0;
        msg_buf.data[7] = 0;
        CAN_send(&msg_buf);

        timer_reset(can_report_timer, 100);
    }
    pt_end(pt);
}