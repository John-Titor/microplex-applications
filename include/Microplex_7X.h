/*
 * Hardware defines for the Microplex 7X, mostly obtained by
 * digging through the sources supplied with the awful
 * Microplex Studio app, with some reference to the (brief)
 * datasheet PDF.
 *
 * SoC:                 MC9S08DZ60
 * CAN:                 TJA1043
 * High-side drivers:   VNQ5050
 * LDO:                 MIC2951
 */

#ifndef _MICROPLEX_7X_H
#define _MICROPLEX_7X_H

#include <mc9s08dz60.h>

/*
 * Memory Map:
 *
 * Z_RAM                   =  READ_WRITE   0x0080 TO 0x00FF;
 * RAM                     =  READ_WRITE   0x0100 TO 0x0E7E;
 * RAM_TEST_RESULT_DEF     =  READ_WRITE   0x0E7F TO 0x0E7F;
 * MY_STK                  =  NO_INIT      0x0E80 TO 0x107F;
 * ROM1                    =  READ_ONLY    0x1080 TO 0x13FF;
 * MCU_EEPROM              =  READ_ONLY    0x1400 TO 0x17FF;
 * EE_FLASH                =  READ_ONLY    0x1900 TO 0x21FF;
 * ROM                     =  READ_ONLY    0x2200 TO 0xAF7B;
 * ROM_TEST_CRC_DEF        =  READ_ONLY    0xAF7C TO 0xAF7F;
 * MY_JMP_VECTORS          =  READ_ONLY    0xAF80 TO 0xAFFF;
 * ROM2                    =  READ_ONLY    0xB000 TO 0xBDFF;
 * ROM_BOOTLOADER          =  READ_ONLY    0xBE00 TO 0xFFBF;
 * INTVECTS                =  READ_ONLY    0xFFC0 TO 0xFFFF;
 *
 *
 * EEPROM magic numbers:
 *
 * PROG_Status:
 *                  0xff00 - programmed: boot user app
 *                  0xfe01 -
 *                  0xfd02 -
 *                  0xfc03 -
 *                  0xfb04 - erased or no program: stay in bootloader
 *
 * Pin              functions
 * ---------------------------------------------------------------------------
 *
 * 1                ground
 * 2                AI_1, FREQ_1
 * 3                +12V
 * 4                CAN_L
 * 5                CAN_H
 * 6                DI_KL15
 * 7                AI_3
 * 8                AI_2
 * 9                DO_HSD_4, PWM_IO4, AI_OP_4
 * 10               DO_HSD_3, PWM_IO3, AI_OP_3
 * 11               DO_HSD_2, PWM_IO2, AI_OP_2
 * 12               DO_HSD_1, PWM_IO1, AI_OP_1
 *
 * Digital inputs   port        pin
 * ---------------------------------------------------------------------------
 *
 * DI_CAN_ERR       PORT_F.3    -   CAN transceiver error signal
 * FREQ_1           PORT_D.2    2   Frequency input (shares pin with AI_1)
 *                                  also on TPM1C0
 *
 * Digital outputs  port        pin
 * ---------------------------------------------------------------------------
 * By function
 *
 * CAN_EN           PORT_F.0    -   CAN transceiver EN
 * CAN_WAKE         PORT_E.5    -   CAN transceiver WAKE
 * DO_20MA_1        PORT_D.0    -   20mA current sink mode for AI_1
 * DO_20MA_2        PORT_A.3    -   20mA current sink mode for AI_2
 * AI_3_PU          PORT_D.3    -   1k pullup on AI_3
 * DO_HSD_1         PORT_D.4    12
 * DO_HSD_2         PORT_D.7    11
 * DO_HSD_3         PORT_D.5    10
 * DO_HSD_4         PORT_D.6    9
 * DO_HSD_SEN       PORT_A.5    -   internal current sense select (STAT_DIS?)
 * DO_POWER         PORT_E.2    -   keep-alive when KL15 is removed
 * DO_30V_10V_1     PORT_F.5    -   AI_1 scale select: 0 = 0-10V, 1 = 0-30V
 * DO_30V_10V_2     PORT_E.0    -   AI_2 scale select: 0 = 0-10V, 1 = 0-30V
 * DO_30V_10V_3     PORT_A.4    -   AI_3 scale select: 0 = 0-10V, 1 = 0-30V
 * CAN_STB_N        PORT_F.2    -   CAN transceiver STB
 *
 * Analog inputs    ADC chan    pin
 * ---------------------------------------------------------------------------
 *
 * AI_1             13          2   (shares pin with FREQ_1)
 * AI_2             6           8
 * AI_3             7           7
 * AI_CS_1          10          -   DO_HSD_1 sense pin
 * AI_CS_2          2           -   DO_HSD_2 sense pin
 * AI_CS_3          11          -   DO_HSD_3 sense pin
 * AI_CS_4          12          -   DO_HSD_4 sense pin
 * AI_KL15          14          6   KL15 voltage
 * AI_OP_1          0           12  DO_HSD_1 voltage
 * AI_OP_2          1           11  DO_HSD_2 voltage
 * AI_OP_3          8           10  DO_HSD_3 voltage
 * AI_OP_4          9           9   DO_HSD_4 voltage
 * AI_TEMP          26          -   Internal temperature sensor
 *
 * PWM outputs      timer1 channel  digital pin
 * ---------------------------------------------------------------------------
 *
 * PWM_IO1          2           -   DO_HSD_1
 * PWM_IO2          5           -   DO_HSD_2
 * PWM_IO3          3           -   DO_HSD_3
 * PWM_IO4          4           -   DO_HSD_4
 *
 * PortA
 * -----
 * DI_CS_2          PORT_A.2    -   DO_HSD_2 status signal
 * DO_20MA_2        PORT_A.3    -   20mA current sink mode for AI_2
 * DO_30V_10V_3     PORT_A.4    -   AI_3 scale select: 0 = 0-10V, 1 = 0-30V
 * DO_HSD_SEN       PORT_A.5    -   internal current sense select (STAT_DIS?)
 * AI_2             PORT_A.6    8   Analog input 2
 * AI_3             PORT_A.7    7   Analog input 3
 *
 * PortB
 * -----
 * DI_CS_1          PORT_B.2    -   DO_HSD_1 status signal
 * DI_CS_3          PORT_B.3    -   DO_HSD_3 status signal
 * DI_CS_4          PORT_B.4    -   DO_HSD_4 status signal
 * AI_1             PORT_B.5    2   Analog input 1
 * DI_KL15          PORT_B.6    6   KL15
 *
 * PortD
 * -----
 * DO_20MA_1        PORT_D.0    -   20mA current sink mode for AI_1
 * FREQ_IN          PORT_D.2    2   Frequency input (shares pin with AI_1)
 * AI_3_PU          PORT_D.3    -   1k pullup on AI_3
 * DO_HSD_1         PORT_D.4    12
 * DO_HSD_3         PORT_D.5    10
 * DO_HSD_4         PORT_D.6    9
 * DO_HSD_2         PORT_D.7    11
 *
 * PortE
 * -----
 * DO_30V_10V_2     PORT_E.0    -   AI_2 scale select: 0 = 0-10V, 1 = 0-30V
 * DO_POWER         PORT_E.2    -   keep-alive when KL15 is removed
 * CAN_WAKE         PORT_E.5    -   CAN transceiver WAKE
 *
 * PortF
 * -----
 * CAN_EN           PORT_F.0    -   CAN transceiver EN
 * CAN_STB_N        PORT_F.2    -   CAN transceiver STB
 * DO_30V_10V_1     PORT_F.5    -   AI_1 scale select: 0 = 0-10V, 1 = 0-30V
 *
 *
 * Notes:
 *  - For normal operation, set CAN_EN and CAN_STB_N high. See TJA1043
 *    datasheet for other modes and the use of the CAN_WAKE signal.
 */

_DI_PIN(DI_CAN_ERR,     F, 3, _DI_NO_PULL);
_DI_PIN(FREQ_1,         D, 2, _DI_NO_PULL);
_DI_PIN(AI_1,           B, 5, _DI_NO_PULL);
_DI_PIN(AI_2,           A, 6, _DI_NO_PULL);
_DI_PIN(AI_3,           A, 7, _DI_NO_PULL);
_DI_PIN(AI_KL15,        B, 6, _DI_NO_PULL);

_DO_PIN(CAN_EN,         F, 0, 1, _DO_SLOW, _DO_WEAK);
_DO_PIN(CAN_WAKE,       E, 5, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_20MA_1,      D, 0, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_20MA_2,      A, 3, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(AI_3_PU,        D, 3, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_HSD_1,       D, 4, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_HSD_2,       D, 7, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_HSD_3,       D, 5, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_HSD_4,       D, 6, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_HSD_SEN,     A, 5, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_POWER,       E, 2, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_30V_10V_1,   F, 5, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_30V_10V_2,   E, 0, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(DO_30V_10V_3,   A, 4, 0, _DO_SLOW, _DO_WEAK);
_DO_PIN(CAN_STB_N,      F, 2, 1, _DO_SLOW, _DO_WEAK);


// TPM1 channels corresponding to the HSD outputs
#define PWM_HSD_1           2
#define PWM_HSD_2           5
#define PWM_HSD_3           3
#define PWM_HSD_4           4

// ADC channel assignments
#define AI_1                13
#define AI_2                6
#define AI_3                7
#define AI_CS_1             10
#define AI_CS_2             2
#define AI_CS_3             11
#define AI_CS_4             12
#define AI_KL15             14
#define AI_OP_1             0
#define AI_OP_2             1
#define AI_OP_3             8
#define AI_OP_4             9
#define AI_TEMP             26

#define AI_MODE_10V         false
#define AI_MODE_30V         true


// ADC scale factors
//
// Measurements in 10-bit mode.
//
// Scaling is performed by taking the accumulated ADC counts
// (sum of ADC_AVG_SAMPLES), multiplying by the scale factor
// and then right-shifting by 12, i.e. the scale factor is a
// 4.12 fixed-point quantity.
//
// To calculate the scaling factor, take mV-per-count and
// multiply by 512.
//
// Current sense outputs are the same but for mA.
//
// AI_1/2/3:
// --------
// 1K pullup mode: TBD
// 20mA mode: TBD (claimed 25mA)

#define ADC_SCALE_FACTOR_30V    17900   // VALIDATED @ 4.860V
#define ADC_SCALE_FACTOR_10V    6065    // VALIDATED @ 4.860V

// AI_OP_1/2/3/4:
// -------------

#define ADC_SCALE_FACTOR_DO_V   16494   // VALIDATED @ 11.46V

// AI_CS_1/2/3/4:
// -------------

#define ADC_SCALE_FACTOR_DO_I   4531    // VALIDATED @ 1.000A

// AI_KL15:
// -------
// Clamped at 11V; mostly useful to help detect input sag and
// avoid faulting outputs when T30 is low.
//

#define ADC_SCALE_FACTOR_KL15   5507    // VALIDATED @ 8.368V

// AI_TEMP
// -------
// Calculated for nominal Vdd (5V)

#define ADC_SCALE_FACTOR_TEMP   610     // XXX VALIDATE

// Initialize pins to suit the module.
//
// Note: analog inputs are configured as digital inputs
//       by default; adc_configure will claim them later.
//
static inline void
board_init()
{
    init_DI_CAN_ERR();  // digital inputs
    init_FREQ_1();

    init_AI_1();        // analog inputs that can be used
    init_AI_2();        // as digital inputs
    init_AI_3();
    init_AI_KL15();

    init_CAN_EN();      // digital outputs
    init_CAN_WAKE();
    init_DO_20MA_1();
    init_DO_20MA_2();
    init_AI_3_PU();
    init_DO_HSD_1();
    init_DO_HSD_2();
    init_DO_HSD_3();
    init_DO_HSD_4();
    init_DO_HSD_SEN();
    init_DO_POWER();
    init_DO_30V_10V_1();
    init_DO_30V_10V_2();
    init_DO_30V_10V_3();
    init_CAN_STB_N();

    // enable interrupts
    __asm__("\tcli");
}

#endif // _MICROPLEX_7X_H
