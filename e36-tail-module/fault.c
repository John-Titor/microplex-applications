/*
 * Faults.
 *
 * Current status is what's being reported right now,
 * and may fluctuate depending on what the system is
 * doing. Latched status is set once and never cleared.
 */

#include <assert.h>

#include "defs.h"

fault_status_t  fault_output[NUM_OUTPUTS];
fault_status_t  fault_system;

void
fault_set_output(output_id_t id, output_fault_t fault)
{
    assert(id < NUM_OUTPUTS);
    assert(fault < 8);

    fault_output[id].fields.current |= 1 << fault;
    fault_output[id].fields.latched |= 1 << fault;
}

void
fault_clear_output(output_id_t id, output_fault_t fault)
{
    assert(id < NUM_OUTPUTS);
    assert(fault < 8);

    fault_output[id].fields.current &= ~(1 << fault);
}

void
fault_set_system(system_fault_t fault)
{
    assert(fault < 8);

    fault_system.fields.current |= 1 <<  fault;
    fault_system.fields.latched |= 1 <<  fault;
}

void
fault_clear_system(system_fault_t fault)
{
    assert(fault < 8);

    fault_system.fields.current &= ~(1 <<  fault);
}

