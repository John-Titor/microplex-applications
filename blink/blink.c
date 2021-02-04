/*
 * Simple pin-blink test for Microplex 7X
 */

#include <stdio.h>
#include <stdlib.h>

#include <board.h>
#include <mscan.h>

// Handler for nonexistent vector 32 is patched in at 
// fixup time as the default handler for vectors that 
// aren't assigned.
void default_handler() __interrupt(32)
{
    // try to send a panic message
    puts("!badirq\n");

    // let the watchdog reset us
    for(;;);
}

void
dump_mem(uint16_t start, uint16_t end)
{
    for (uint32_t addr = start; addr < end; addr += 16) {
        uint8_t *ptr = (uint8_t *)addr;
        uint8_t sum = 0x13 + ((addr >> 8) & 0xff) + (addr & 0xff);
        for (uint8_t i = 0; i < 16; i++) {
            sum += ptr[i];
        }
        sum = ~sum;
        debug("S113%04X"
              "%02X%02X%02X%02X%02X%02X%02X%02X"
              "%02X%02X%02X%02X%02X%02X%02X%02X"
              "%02X",
              (unsigned)addr,
              ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7],
              ptr[8], ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15],
              sum);
        __RESET_WATCHDOG();
        for (uint32_t x = 0; x < 20000; x++) {}
    }
}

void
main()
{
    __RESET_WATCHDOG();

    // configure pins
    board_init();

    // configure CAN
    CAN_init(CAN_BR_125, CAN_FM_NONE, NULL);

    // Sign on; initial "X" gets eaten by the programmer
    puts("Multiplex 7X test firmware");

    // turn on HSD_1
    set_DO_HSD_1(true);

    for (;;) {
        __RESET_WATCHDOG();
        for (short i = 0; i < 20000; i++);
    }
}
