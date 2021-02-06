/*
 * Timers and timebase
 *
 * Using TPM2C2
 *
 * FFCLK is 1MHz, so we run with a /1 prescaler to count microseconds.
 *
 * We maintain a 32-bit timebase which will wrap after ~71 minutes,
 * so code must be careful about absolute time values.
 *
 * A note on time_wait_us: the maximum delay is limited to u_int16 both
 * for efficiency (waiting longer than 64ms is not friendly to other parts
 * of the system) and also to make it safe to use in a __critical region;
 * time_us can only handle one wrap before it needs the overflow handler to
 * run and adjust the timebase high word.
 * 
 */

#include <assert.h>
#include <stdlib.h>

#include <timer.h>

static timer_t      *timer_list;
static timer_call_t *timer_call_list;
static volatile __data uint16_t timebase_high_word;

void
time_init(void)
{
    TPM2SC = 0;
    TPM2SC_CLKSx = 2;   // select fixed clock
    TPM2SC_PS = 0;      // /1 prescaler
    TPM2MOD = 0;        // clear modulus
    TPM2CNT = 0;        // clear counter
    TPM2SC_TOIE = 1;    // enable overflow interrupt

    TPM2C1SC = 0;
    TPM2C1SC_MS1A = 1;  // output compare
    TPM2C0V = 1000;     // set initial deadline
    TPM2C1SC_CH1IE = 1; // enable interrupt
}

#pragma save
#pragma nooverlay
microseconds
time_us(void)
__critical {
    union {
        microseconds us;
        uint16_t    w[2];
    } tv;

    // get the "current" time value
    tv.w[0] = timebase_high_word;
    tv.w[1] = TPM2CNT;

    // if we have raced with overflow, increment the
    // high word and re-fetch the low word
    if (TPM2SC & TPM2SC_TOF_MASK)
    {
        tv.w[0]++;
        tv.w[1] = TPM2CNT;
    }
    return tv.us;
}
#pragma restore

bool
time_elapsed_us(microseconds since_us, uint16_t interval_us)
{
    return (time_us() - since_us) >= interval_us;
}

void
time_wait_us(uint16_t delay_us)
{
    microseconds then = time_us();

    while (!time_elapsed_us(then, delay_us)) {
    }
}

void
Vtpm2ovf_handler(void)
__interrupt(VectorNumber_Vtpm2ovf)
{
    timebase_high_word++;
    TPM2SC_TOF = 0;
}

void
timer_register(timer_t *timer)
__critical {
    assert(timer != NULL);

    // singly-linked insertion at head
    timer->_next = timer_list;
    timer_list = timer;
}

void
timer_call_register(timer_call_t *call)
__critical {
    assert(call != NULL);
    assert(call->callback != NULL);

    // singly-linked insertion at head
    call->_next = timer_call_list;
    timer_call_list = call;
}

void Vtpm2ch1_handler(void)
__interrupt(VectorNumber_Vtpm2ch1)
{
    // re-set compare for next tick
    // must update TPM2C1V *after* clearing the interrupt
    TPM2C1SC &= ~TPM2C1SC_CH1F_MASK;
    TPM2C1V += 1000;

    // update timers
    for (timer_t *t = timer_list;
         t != NULL;
         t = t->_next) {
        if (t->delay_ms > 0) {
            t->delay_ms--;
        }
    }

    // run timer calls
    for (timer_call_t *tc = timer_call_list;
         tc != NULL;
         tc = tc->_next) {

        // if the call is active...
        if (tc->delay_ms > 0) {
            // and the delay expires...
            if (--tc->delay_ms == 0) {
                // run the callback
                tc->callback();
                // and reload the delay
                tc->delay_ms = tc->period_ms;
            }
        }
    }
}
