/*
 * Board/module-specific defines.
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "mc9s08dz60.h"

// XXX the resulting code is easy to read, but it could be more compact;
//     in the end we really just need 24 bytes of data copied to 24
//     registers...

//////////////////////////////////////////////////////////////////////
// declare a digital input & helper functions
//
#define _DI_PULL_UP     1
#define _DI_NO_PULL     0

#define _DI_PIN(_name, _port, _pin, _pull)                          \
    static inline bool test_ ## _name ()                            \
    {                                                               \
        return _PT ## _port ## D.Bits.PT ## _port ## D ## _pin;     \
    }                                                               \
    static inline void init_ ## _name ()                            \
    {                                                               \
        _PT ## _port ## DD.Bits.PT ## _port ## DD ## _pin = 0;      \
        _PT ## _port ## PE.Bits.PT ## _port ## PE ## _pin = _pull;  \
    } struct hack

//////////////////////////////////////////////////////////////////////
// declare a digital output & helper functions
//
#define _DO_FAST        0
#define _DO_SLOW        1
#define _DO_WEAK        0
#define _DO_STRONG      1

#define _DO_PIN(_name, _port, _pin, _default, _slow, _strong)       \
    static inline void set_ ## _name (bool _v)                      \
    {                                                               \
        _PT ## _port ## D.Bits.PT ## _port ## D ## _pin = _v;       \
    }                                                               \
    static inline void init_ ## _name ()                            \
    {                                                               \
        _PT ## _port ## D.Bits.PT ## _port ## D ## _pin = _default; \
        _PT ## _port ## DD.Bits.PT ## _port ## DD ## _pin = 1;      \
        _PT ## _port ## SE.Bits.PT ## _port ## SE ## _pin = _slow;  \
        _PT ## _port ## DS.Bits.PT ## _port ## DS ## _pin = _strong;\
    } struct hack

//////////////////////////////////////////////////////////////////////
// debug output via CAN
//
#if !defined(RELEASE) && defined(WITH_mscan)
# define debug(fmt, args...)    printf(fmt "\n", ##args)
#else
# define debug(fmt, args...)    do { } while(0)
#endif


#ifdef BOARD_MICROPLEX_7X
#include "Microplex_7X.h"
#else
#error Unsupported board
#endif

#endif // _BOARD_H_
