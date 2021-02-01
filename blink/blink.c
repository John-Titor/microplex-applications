/*
 * Simple pin-blink test for Microplex 7X
 */

#include <board.h>

// Handler for nonexistent vector 32 is patched in as the
// default handler for vectors that aren't assigned.
void default_handler() __interrupt(32)
{
    for(;;);
}

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


