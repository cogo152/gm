    .syntax unified

#include "core.h"

GLOBAL_FUNCTION set_MSP
    msr msp, r0
    bx lr

GLOBAL_FUNCTION get_MSP
    mrs r0, msp
    bx lr
    
GLOBAL_FUNCTION set_PSP
    msr psp, r0
    bx lr
    
GLOBAL_FUNCTION get_PSP
    mrs r0, psp
    bx lr

GLOBAL_FUNCTION set_Mode
    msr control, r0
    bx lr