/*
 * General definitions.
 */

#include <stdbool.h>
#include <stdint.h>

#include <board.h>
#include <pt.h>

/*
 * CAN threads.
 */

extern void can_listen(struct pt *pt);
extern void can_report(struct pt *pt);

/*
 * Brake light behaviours.
 */

extern void brake_thread(struct pt *pt);
extern void brake_light_request(bool on);

/*
 * Analog monitors.
 */

typedef enum {
    // Fast-sampled channels.
    MON_KL15,

    // Slow-sampled channels.
    MON_FUEL_LEVEL,
} monitor_channel_t;

extern void monitor_init(void);
extern uint16_t monitor_get(monitor_channel_t channel);

/*
 * High-side driver outputs.
 */

#define NUM_OUTPUTS 4

typedef enum {
    OUTPUT_BRAKE_L,
    OUTPUT_BRAKE_R,
    OUTPUT_TAIL,
    OUTPUT_RAIN
} output_id_t;

extern void output_thread(struct pt *pt);
extern void output_request(uint8_t channel, bool on);
extern void do_output_check(void);

/*
 * Faults
 */

typedef enum {
    OUT_FAULT_OPEN,
    OUT_FAULT_STUCK,
    OUT_FAULT_OVERLOAD,
    _OUT_FAULT_MAX,
} output_fault_t;

typedef enum
{
    SYS_FAULT_CAN_TIMEOUT,
    SYS_FAULT_OVERTEMP,
    SYS_FAULT_MAX,
} system_fault_t;

typedef union
{
    struct {
        uint8_t     current:4;
        uint8_t     latched:4;
    } fields;
    uint8_t     raw;
} fault_status_t;

extern fault_status_t   fault_output[NUM_OUTPUTS];
extern fault_status_t   fault_system;

extern void fault_set_output(output_id_t id, output_fault_t fault);
extern void fault_clear_output(output_id_t id, output_fault_t fault);
extern void fault_set_system(system_fault_t fault);
extern void fault_clear_system(system_fault_t fault);

