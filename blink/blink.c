/*
 * Simple pin-blink test for Microplex 7X
 */

#include <board.h>

void
main()
{
    board_init();
    set_DO_HSD_1(1);
    for (;;);
}
