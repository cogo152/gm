    .syntax unified

    #include "syscall.h"
    
    #include "core.h"
    #include "system.h"

GLOBAL_FUNCTION SVC_Handler
    push {lr}
    
    mrs r0, psp
    ldr r1, [r0,#24]
    sub r1, r1, #2
    ldrh r2, [r1]
    bic r2, r2, #0xFF00

    cmp r2, #SVC_SYSTEM_START
    beq svc_system_start

    cmp r2, #SVC_SYSTEM_STOP
    beq svc_system_stop
    
svc_system_start :
    bl system_start
    mov r0, #CORE_MODE_USER
    bl core_mode_set
    pop {pc}

svc_system_stop :
    bl system_stop
    mov r0, #CORE_MODE_KERNEL
    bl core_mode_set
    pop {pc}



