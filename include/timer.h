/*
 * Timers and timebase
 */

#include <stdint.h>

#include "mc9s08dz60.h"

typedef struct _timer
{
    struct _timer   *_next;
    uint16_t        delay_ms;
} timer_t;

typedef struct _timer_call
{
    struct _timer_call *_next;
    uint16_t        delay_ms;
    void            (*callback)();  // function to call
    uint16_t        period_ms;      // tick interval between calls, 0 for one-shot
} timer_call_t;

typedef uint32_t microseconds;

extern void         time_init(void);
extern microseconds time_us(void);
extern void         timer_register(timer_t *timer);
extern void         timer_call_register(timer_call_t *call);

#define timer_reset(_timer, _delay) __critical do { (_timer).delay_ms = delay; } while(0)
#define timer_expired(_timer)       ((_timer).delay_ms == 0)

extern void Vtpm2ovf_handler(void) __interrupt(VectorNumber_Vtpm2ovf);
extern void Vtpm2ch1_handler(void) __interrupt(VectorNumber_Vtpm2ch1);
