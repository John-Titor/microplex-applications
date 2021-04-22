/*
 * General definitions.
 */

#ifndef _DEFS_H
#define _DEFS_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "config.h"

#include <board.h>
#include <mscan.h>
#include <pt.h>


/*
 * Console logging / debug thread.
 */

extern struct pt pt_console_report;

extern void console_report(struct pt *pt);

#ifdef CONSOLE_DO_LOG
# define LOG(fmt, args...)  printf(fmt " \n", ## args)
#else
# define LOG(fmt, args...)  do {} while(0)
#endif


/*
 * CAN threads.
 */

extern struct pt pt_can_listener;
extern struct pt pt_can_report_fuel;
extern struct pt pt_can_report_diags;

extern unsigned can_rx_count;

extern void can_listen(struct pt *pt);
extern void can_report_fuel(struct pt *pt);
extern void can_report_diags(struct pt *pt);

extern struct pt pt_cas_jbe_emulator;

extern void cas_jbe_recv(const CAN_message_t *msg);
extern void cas_jbe_emulator(struct pt *pt);


/*
 * Various light behaviours.
 */

extern struct pt pt_brakes;
extern struct pt pt_tails;

typedef enum {
    LIGHT_OFF,
    LIGHT_ON,
    LIGHT_FAULT,
    _LIGHT_STATE_MAX
} light_state_t;

extern light_state_t brake_light_requested;
extern light_state_t tail_light_requested;
extern light_state_t rain_light_requested;

extern void brake_thread(struct pt *pt);
extern void tails_thread(struct pt *pt);
extern void brake_light_request(light_state_t state);
extern void tail_light_request(light_state_t state);
extern void rain_light_request(light_state_t state);


/*
 * Analog monitors.
 */

typedef enum {
    // Fast-sampled channels.
    MON_T15_VOLTAGE,
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
    MON_TEMPERATURE,
    _MON_ID_MAX
} monitor_channel_t;

extern void monitor_init(void);
extern uint16_t monitor_get(monitor_channel_t channel);


/*
 * High-side driver outputs.
 */

typedef enum {
    OUTPUT_BRAKE_L,     // left brake
    OUTPUT_BRAKE_R,     // right brake
    OUTPUT_TAILS,       // tail lights
    OUTPUT_RAIN,        // rain light
    _OUTPUT_ID_MAX
} output_id_t;

typedef enum {
    OUTPUT_STATE_OFF,
    OUTPUT_STATE_ON,
    _OUTPUT_STATE_MAX
} output_state_t;

extern struct pt pt_output[_OUTPUT_ID_MAX];
extern uint8_t output_pin_state;

extern void output_thread(struct pt *pt, output_id_t output);
extern void output_request(output_id_t output, output_state_t state); 


/*
 * Faults.
 *
 * XXX due to current encoding strategy, only 4 output
 *     and 4 system faults are supported
 */

typedef enum {
    OUT_FAULT_OPEN,
    OUT_FAULT_STUCK,
    OUT_FAULT_OVERLOAD,
    _OUT_FAULT_MAX,
} output_fault_t;

typedef enum {
    SYS_FAULT_T15_PLAUSIBILITY,
    SYS_FAULT_CAN_TIMEOUT,
    SYS_FAULT_OVER_TEMPERATURE,
    _SYS_FAULT_MAX,
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

#endif // _DEFS_H