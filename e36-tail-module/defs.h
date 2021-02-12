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
    MON_OUT_V_1,
    MON_OUT_V_2,
    MON_OUT_V_3,
    MON_OUT_V_4,
    MON_OUT_I_1,
    MON_OUT_I_2,
    MON_OUT_I_3,
    MON_OUT_I_4,

    // Slow-sampled channels.
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
    OUTPUT_RAIN,
    _OUTPUT_ID_MAX
} output_id_t;

typedef enum {
    OUTPUT_STATE_OFF,
    OUTPUT_STATE_ON,
    OUTPUT_STATE_TIMEOUT
} output_state_t;

extern void output_thread(struct pt *pt);
extern void output_request(uint8_t channel, output_state_t state);

/*
 * Faults.
 */

typedef enum {
    OUT_FAULT_OPEN,
    OUT_FAULT_STUCK,
    OUT_FAULT_OVERLOAD,
    _OUT_FAULT_MAX,
} output_fault_t;

typedef enum {
    SYS_FAULT_CAN_TIMEOUT,
    SYS_FAULT_OVERTEMP,
    SYS_FAULT_MAX,
    // XXX fuel level sensor plausibility
    // XXX KL15 voltage plausibility
} system_fault_t;

typedef union {
    struct {
        uint8_t     current: 4;
        uint8_t     latched: 4;
    } fields;
    uint8_t     raw;
} fault_status_t;

extern fault_status_t   fault_output[];
extern fault_status_t   fault_system;

extern void fault_set_output(output_id_t id, output_fault_t fault);
extern void fault_clear_output(output_id_t id, output_fault_t fault);
extern void fault_set_system(system_fault_t fault);
extern void fault_clear_system(system_fault_t fault);

