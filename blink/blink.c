/*
 * Simple pin-blink test for Microplex 7X
 */

#include <stdio.h>
#include <stdlib.h>

#include <board.h>
#include <mscan.h>
#include <timer.h>

// Handler for nonexistent vector 32 is patched in at
// fixup time as the default handler for vectors that
// aren't assigned.
void default_handler() __interrupt(32)
{
    // try to send a panic message
    puts("!badirq\n");

    // let the watchdog reset us
    for (;;);
}

#if 0
// per-IRQ bad interrupt handlers for finer-grained
// interrupt error debugging

#define BADIRQ(_num)                        \
    void handler_ ## _num () __interrupt(_num)  \
    {                                           \
        puts("irq " # _num);                    \
        for(;;);                                \
    }

BADIRQ(VectorNumber_Vacmp2)
BADIRQ(VectorNumber_Vacmp1)
BADIRQ(VectorNumber_Vcantx)
BADIRQ(VectorNumber_Vcanrx)
BADIRQ(VectorNumber_Vcanerr)
BADIRQ(VectorNumber_Vcanwu)
BADIRQ(VectorNumber_Vrtc)
BADIRQ(VectorNumber_Viic)
BADIRQ(VectorNumber_Vadc)
BADIRQ(VectorNumber_Vport)
BADIRQ(VectorNumber_Vsci2tx)
BADIRQ(VectorNumber_Vsci2rx)
BADIRQ(VectorNumber_Vsci2err)
BADIRQ(VectorNumber_Vsci1tx)
BADIRQ(VectorNumber_Vsci1rx)
BADIRQ(VectorNumber_Vsci1err)
BADIRQ(VectorNumber_Vspi)
//BADIRQ(VectorNumber_Vtpm2ovf)
//BADIRQ(VectorNumber_Vtpm2ch1)
BADIRQ(VectorNumber_Vtpm2ch0)
BADIRQ(VectorNumber_Vtpm1ovf)
BADIRQ(VectorNumber_Vtpm1ch5)
BADIRQ(VectorNumber_Vtpm1ch4)
BADIRQ(VectorNumber_Vtpm1ch3)
BADIRQ(VectorNumber_Vtpm1ch2)
BADIRQ(VectorNumber_Vtpm1ch1)
BADIRQ(VectorNumber_Vtpm1ch0)
BADIRQ(VectorNumber_Vlol)
BADIRQ(VectorNumber_Vlvd)
BADIRQ(VectorNumber_Virq)
BADIRQ(VectorNumber_Vswi)
#endif

#if 0
// memory dump utility
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
#endif

volatile bool ticked;

void
tick(void)
{
    ticked = true;
}
volatile timer_call_t tick_call = { .delay_ms = 1500, .period_ms = 3000, .callback = tick };
//volatile timer_call tick_call = { .delay_ms = 15000, .period_ms = 0, .callback = tick };

void
main()
{
    __RESET_WATCHDOG();

    // configure pins, etc.
    board_init();

    // start the timebase and timer callouts
    time_init();

    // configure CAN
    CAN_init(CAN_BR_125, CAN_FM_NONE, NULL);

    // Sign on; initial "X" gets eaten by the programmer
    debug("Multiplex 7X test firmware");
    __RESET_WATCHDOG();

    // turn on HSD_1
    set_DO_HSD_1(true);

    // set up timer callback
    timer_call_register(&tick_call);

    for (;;) {
        __RESET_WATCHDOG();
        if (ticked) {
            debug("tick %lu", time_us());
            ticked = false;
        }
    }
}
