/*
 * Interrupt thunks.
 *
 * Since the real vector table is in the ROM, the ROM 
 * code calls program-provided thunks in the 0xaf80-0xb000 range
 * to deliver interrupts.
 * Each thunk occupies a 4-byte slot. The reset vector must be
 * populated in order for the ROM to be able to start the program.
 * Just to keep things exciting, vectors are numbered backwards
 * with the reset thunk at 0xaffc being vector 0.
 *
 * The SDCC interrupt magic for the HCS08 wants to generate the
 * "normal" vector table, so don't use that.  Instead, ensure 
 * this macro is included in the same file as the handler
 * is defined, as it supplies a suitable prototype.
 */

typedef struct 
{
    uint8_t jmp;
    uint16_t addr;
    uint8_t pad;
} _interrupt_thunk_t;

#define INTERRUPT(_vector, _handler)                                                \
static void _handler (void) __interrupt;                                            \
__at(0xaffc - (4 * _vector)) const _interrupt_thunk_t _interrupt_ ## _vector ## _thunk = {\
    .jmp = 0xcc,                                                                    \
    .addr = (uint16_t)(_handler),                                                   \
    .pad = 0x9d                                                                     \
}

#define ENTRY(_entrypoint)                                                          \
__at(0xaffc) const _interrupt_thunk_t _entrypoint_thunk = {                         \
    .jmp = 0xcc,                                                                    \
    .addr = (uint16_t)(_entrypoint),                                                \
    .pad = 0x9d                                                                     \
}
