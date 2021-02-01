/*
 * Simple pin-blink test for Microplex 7X
 */

#include <stdlib.h>
#include <board.h>
#include <mscan.h>

// Handler for nonexistent vector 32 is patched in at 
// fixup time as the default handler for vectors that 
// aren't assigned.
void default_handler() __interrupt(32)
{
    // let the watchdog reset us
    for(;;);
}

void
main()
{
    __RESET_WATCHDOG();

    // configure pins
    board_init();

    // configure CAN
    CAN_init(CAN_BR_125, CAN_FM_NONE, NULL);

    CAN_message msg = {
        .id = {
            .mscan_id = MSCAN_ID(0x123)
        },
        .data = { 0x01, 0x02 },
        .dlc = 2,
        .priority = 1
    };
    CAN_send(&msg);

    // turn on HSD_1
    set_DO_HSD_1(true);

    for (;;) {
        __RESET_WATCHDOG();
        for (short i = 0; i < 20000; i++);
    }
}
