/*
 * Simple pin-blink test for Microplex 7X
 */

#include <board.h>

void
main()
{
    __RESET_WATCHDOG();

    // configure port D
    _PTDDD.Byte = 0xf0;
    _PTDD.Byte = 0xf0;

    for (;;) {
        __RESET_WATCHDOG();
        for (short i = 0; i < 20000; i++);
    }
}


