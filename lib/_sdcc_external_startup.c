/*
 * Early HCS08 startup code; (re)initializes clocks, etc.
 *
 * - 8MHz external crystal oscillator
 * - 40MHz MCGOUT (CPU clock)
 * - 20MHz BUSCLK
 * - 8MHz MCGERCLK
 */

#include <stdint.h>
#include <mc9s08dz60.h>

void
_sdcc_external_startup()
{
    __RESET_WATCHDOG();

    // Generic startup reversed from a trivial app
    //
    // Writing SOPT1/2 seems pointless, as surely the ROM has already done this?

    // set STOPE, 1s COP timeout, IIC on PTF2/3
    _SOPT1.Byte = 0xe0;

    // 1kHz COP clock, non-window mode, ADC on RTC overflow, MCLK disabled
    _SOPT2.Byte = 0x00;

    // set LVDRE, LVDSE, LVDE, BGBE; reset on low-voltage detect
    _SPMSC1.Byte = 0x1d;

    // LVD set for 5V mode
    _SPMSC2.Byte = 0x30;

    // copy MCG trim values from NVRAM
    _MCGTRM.Byte = *(uint8_t *)0xffaf;
    _MCGSC.Byte = *(uint8_t *)0xffae;

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
}
