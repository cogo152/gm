    .syntax unified

    #include "syscall.h"
    
    #include "core_cpu.h"
    #include "system.h"

GLOBAL_FUNCTION SVC_Handler
    push {lr}
    
    mrs r0, psp
    ldr r1, [r0, #24]
    subs r1, r1, #2
    ldrh r2, [r1]
    ldr r3, = 0xFF00
    bics r2, r2, r3
    lsls r2, #1

    ldr r3, =jump_table
    adds r3, r3, r2
    mov pc, r3

jump_table :
    b svc_system_start
    b svc_system_stop
    b svc_default

svc_system_start :
    bl system_start
    movs r0, #CPU_MODE_USER
    bl cpu_mode_set
    pop {pc}

svc_system_stop :
    bl system_stop
    movs r0, #CPU_MODE_KERNEL
    bl cpu_mode_set
    pop {pc}

svc_default :
    pop {pc}


