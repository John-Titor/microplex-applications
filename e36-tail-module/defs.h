/*
 * General definitions.
 */

#include <stdbool.h>
#include <stdint.h>

#include <board.h>
#include <pt.h>

extern void can_listen(struct pt *pt);
extern void can_report(struct pt *pt);
extern void output_thread(struct pt *pt);

typedef enum {
    // fast-sampled channels
    MON_DO_CURRENT_1,
    MON_DO_CURRENT_2,
    MON_DO_CURRENT_3,
    MON_DO_CURRENT_4,

    // slow-sampled channels
    MON_FUEL_LEVEL,
} monitor_channel_t;

extern void monitor_init(void);
extern uint16_t monitor_get(monitor_channel_t channel);

/*
 * High-side driver outputs.
 */

typedef enum {
    OUTPUT_BRAKE_L,
    OUTPUT_BRAKE_R,
    OUTPUT_TAIL,
    OUTPUT_RAIN
};

typedef enum {
    OUT_STATE_OFF,
    OUT_STATE_ON,
    OUT_STATE_OPEN_CIRCUIT,
    _OUT_STATE_PERMANENT_FAULT_STATES,
    OUT_STATE_OVERTEMP,
    OUT_STATE_OVERLOAD,
    OUT_STATE_STUCK
} output_status_t;

extern void output_init(void);
extern void do_output_check(void);
extern void output_request(uint8_t channel, bool on);
extern uint8_t output_status(uint8_t channel);

/*
 * CAN
 */

extern void do_can_listen(void);
extern void do_can_report(void);

