/*
 * Board-specific defines.
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "mc9s08dz60.h"

#define _DI_PIN(_name, _port, _pin, _pull)                      \
static const inline bool test_ ## _name ()                      \
{                                                               \
    return _PT ## _port ## D.Bits.PT ## _port ## D ## _pin;     \
}                                                               \
static const inline void init_ ## _name ()                      \
{                                                               \
    _PT ## _port ## DD.Bits.PT ## _port ## DD ## _pin = 0;      \
    _PT ## _port ## PE.Bits.PT ## _port ## PE ## _pin = _pull;  \
} struct hack

#define _DI_PULL_UP     1
#define _DI_NO_PULL     0

#define _DO_PIN(_name, _port, _pin, _default, _slow, _strong)   \
static const inline void set_ ## _name (bool _v)                \
{                                                               \
    _PT ## _port ## D.Bits.PT ## _port ## D ## _pin = _v;       \
}                                                               \
static const inline void init_ ## _name ()                      \
{                                                               \
    _PT ## _port ## D.Bits.PT ## _port ## D ## _pin = _default; \
    _PT ## _port ## DD.Bits.PT ## _port ## DD ## _pin = 1;      \
    _PT ## _port ## SE.Bits.PT ## _port ## SE ## _pin = _slow;  \
    _PT ## _port ## DS.Bits.PT ## _port ## DS ## _pin = _strong;\
} struct hack

static inline void
chip_init()
{
	_SOPT1.Byte = 0xe0; // STOPE | COPT0 | COPT1
	_SOPT2.Byte = 0;
	_SPMSC1.Byte = 0x1d; // LVDRE | LVDSE | LVDE | BGBE;
	_SPMSC2.Byte = 0x30; // LVDV | LVWV
}

#ifdef BOARD_MICROPLEX_7X
#include "Microplex_7X.h"
#else
#error Unsupported board
#endif

#endif // _BOARD_H_
