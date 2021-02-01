/*
 * Early HCS08 startup code; (re)initializes clocks, etc.
 */

#include <stdint.h>
#include <mc9s08dz60.h>

#include <interrupt.h>

void
_sdcc_external_startup()
{
    __RESET_WATCHDOG();

    // Generic startup reversed from a trivial app
    //
    // Writing SOPT1/2 seems pointless, as surely the ROM has already done this?

//    2200 a6 e0           LDA        #0xe0
//    2202 c7 18 02        STA        SOPT1                                            = ??
    _SOPT1.Byte = 0xe0;
//    2205 4f              CLRA
//    2206 c7 18 03        STA        SOPT2                                            = ??
    _SOPT2.Byte = 0x00;
//    2209 a6 1d           LDA        #0x1d
//    220b c7 18 09        STA        SPMSC1                                           = ??
    _SPMSC1.Byte = 0x1d;
//    220e a6 30           LDA        #0x30
//    2210 c7 18 0a        STA        SPMSC2                                           = ??
    _SPMSC2.Byte = 0x30;
//    2213 c6 ff af        LDA        DAT_ffaf
//    2216 b7 4a           STA        MCGTRM                                           = ??
    _MCGTRM.Byte = *(uint8_t *)0xffaf;
//    2218 c6 ff ae        LDA        DAT_ffae
//    221b b7 4b           STA        MCGSC                                            = ??
    _MCGSC.Byte = *(uint8_t *)0xffae;
//    221d 6e 26 49        MOV        #0x26,MCGC2                                      = ??
    _MCGC2.Byte = 0x26;
//    2220 6e ba 48        MOV        #0xba,MCGC1                                      = ??
    _MCGC1.Byte = 0xba;

//                     LAB_2223                                        XREF[1]:     2223(j)  
//    2223 03 4b fd        BRCLR      0x1,MCGSC,LAB_2223                               = ??
    while (!(_MCGSC.Byte & (1<<2))) {
    }
//                     LAB_2226                                        XREF[1]:     2226(j)  
//    2226 08 4b fd        BRSET      0x4,MCGSC,LAB_2226                               = ??
    while (_MCGSC.Byte & (1<<4)) {
    }
//                     LAB_2229                                        XREF[1]:     222f(j)  
//    2229 b6 4b           LDA        MCGSC                                            = ??
//    222b a4 0c           AND        #0xc
//    222d a1 08           CMP        #0x8
//    222f 26 f8           BNE        LAB_2229
    while ((_MCGSC.Byte & 0x0c) != 0x8) {
    }

//    2231 6e 92 48        MOV        #0x92,MCGC1                                      = ??
    _MCGC1.Byte = 0x92;
//    2234 6e 45 4c        MOV        #0x45,MCGC3                                      = ??
    _MCGC3.Byte = 0x45;

//                     LAB_2237                                        XREF[1]:     2237(j)  
//    2237 0b 4b fd        BRCLR      0x5,MCGSC,LAB_2237                               = ??
    while (!(_MCGSC.Byte & (1<<5))) {
    }
//                     LAB_223a                                        XREF[1]:     223a(j)  
//    223a 0d 4b fd        BRCLR      0x6,MCGSC,LAB_223a                               = ??
    while (!(_MCGSC.Byte & (1<<6))) {
    }

//    223d c6 24 f0        LDA        DAT_24f0                                         = 01h
//    2240 4b 05           DBNZA      LAB_2247
//    2242 6e 10 48        MOV        #0x10,MCGC1                                      = ??
//    2245 20 03           BRA        LAB_224a
//                     LAB_2247                                        XREF[1]:     2240(j)  
//    2247 6e 08 48        MOV        #0x8,MCGC1                                       = ??
    _MCGC1.Byte = 0x10;

//                     LAB_224a                                        XREF[2]:     2245(j), 2250(j)  
//    224a b6 4b           LDA        MCGSC                                            = ??
//    224c a4 0c           AND        #0xc
//    224e a1 0c           CMP        #0xc
//    2250 26 f8           BNE        LAB_224a
    while ((_MCGSC.Byte & 0x0c) != 0x0c) {
    }

}

// Make sure there's a thunk for the entrypoint, as the ROM won't 
// run the program otherwise...
// Annoyingly, there's no global symbol, so we have to know the magic
// entrypoint address.
//
ENTRY(0x2200);
