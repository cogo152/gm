    .syntax unified

#include "core.h"

GLOBAL_FUNCTION core_msp_set
    msr msp, r0
    isb
    bx lr

GLOBAL_FUNCTION core_msp_get
    mrs r0, msp
    bx lr
    
GLOBAL_FUNCTION core_psp_set
    msr psp, r0
    isb
    bx lr
    
GLOBAL_FUNCTION core_psp_get
    mrs r0, psp
    bx lr

GLOBAL_FUNCTION core_mode_set
    msr control, r0
    isb
    bx lr