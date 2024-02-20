    .syntax unified

    #include "systemcall.h"
    #include "system.h"

GLOBAL_FUNCTION SVC_Handler
    mrs r0, psp
    ldr r1, [r0,#24]
    sub r1, r1, #2
    ldrh r2, [r1]
    bic r2, r2, #0xFF00
    cmp r2, 1
    beq 