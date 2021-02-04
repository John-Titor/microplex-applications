/*
 * Early HCS08 startup code.
 *
 * - 8MHz external crystal oscillator
 * - 40MHz MCGOUT (CPU clock)
 * - 20MHz BUSCLK
 * - 8MHz MCGERCLK
 */

#include <stdint.h>
#include <mc9s08dz60.h>

char
_sdcc_external_startup()
{
    __RESET_WATCHDOG();

    // Generic startup reversed from a trivial app
    //
    // SOPTx, SPMSCx and MCGCTRM are set by the ROM and
    // can't be set here.
    //
    // The ROM de-configures the PLL before launching the
    // user app, so we go through the process to set it
    // back up again.

    // Enable external reference clock for 8MHz crystal,
    // enable MCGERCLK
    _MCGC2.Byte = 0x26;

    // Switch to external clock at maximum divider
    // CLKS = external reference
    // RDIV = /128 (62.5HKz)
    // IRCLKEN = 1
    _MCGC1.Byte = 0xba;

    // wait for external oscillator init to complete
    while (!(_MCGSC.Byte & (1<<1))) {
    }
    // wait for IREFST to clear
    while (_MCGSC.Byte & (1<<4)) {
    }
    // wait for CLKST to match CLKS
    while ((_MCGSC.Byte & 0x0c) != 0x8) {
    }

    // Switch to external clock at /4
    // CLKS = external reference
    // RDIV = /4 (2MHz)
    // IRCLKEN = 1
    _MCGC1.Byte = 0x92;

    // Configure PLL for refclk * 20
    // PLLS = PLL selected
    // VDIV = *20 (40MHz)
    _MCGC3.Byte = 0x45;

    // wait for PLLST / PLL to be selected
    while (!(_MCGSC.Byte & (1<<5))) {
    }
    // wait for LOCK / PLL locked
    while (!(_MCGSC.Byte & (1<<6))) {
    }

    // Switch to PLL clock
    // CLKS = PLL
    // RDIV = /4 (2MHz)
    _MCGC1.Byte = 0x10;

    // wait for CLKST to match CLKS - PLL selected
    while ((_MCGSC.Byte & 0x0c) != 0x0c) {
    }

    // clear RAM / BSS, since the SDCC startup code doesn't; don't
    // clear the last 0x80 bytes since the stack is there...
    for (uint8_t *p = (uint8_t *)0x80; p < (uint8_t *)0x1000; p++) {
        *p = 0;
    }

    return 0;
}
