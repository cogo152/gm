#include "core_cpu.h"

GLOBAL_FUNCTION cpu_msp_set
    msr msp, r0
    isb
    bx lr

GLOBAL_FUNCTION cpu_msp_get
    mrs r0, msp
    bx lr
    
GLOBAL_FUNCTION cpu_psp_set
    msr psp, r0
    isb
    bx lr
    
GLOBAL_FUNCTION cpu_psp_get
    mrs r0, psp
    bx lr

GLOBAL_FUNCTION cpu_mode_set
    msr control, r0
    isb
    bx lr

GLOBAL_FUNCTION cpu_mode_get
    mrs r0, control
    bx lr