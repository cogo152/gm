    .syntax unified

    #include "process.h"
    #include "systemcall.h"


GLOBAL_FUNCTION saveContext
    mrs r1, psp
    stmdb r1!, {r4-r11}
    msr psp, r1
    str r1, [r0]
    bx lr

GLOBAL_FUNCTION retrieveContext
    ldr r1, [r0]
    ldmia r1!, {r4-r11}
    msr psp, r1
    str r1, [r0]
    bx lr

GLOBAL_FUNCTION startProcessContext
    svc INIT_TIMER
    pop {r0-r12, lr}
    pop {r0}
    pop {r1}
    blx r0

    // //till lr everthing is successful
    // now pc must to point init process stack of function pointer which is thumb set#
    //svc 0 // stacking and unstacking in inital proccss stack but does not affect dumy settings +
    //

    // handler prototype. being copied to sram stack to execute process function
GLOBAL_FUNCTION mainHandler
    ldr	r0, [pc, #4]
    ldr	r1, [r0]
    blx	r0
    svc	1 // loop bitince napcaz kernel moda mi dönmek lazim ? buraya geri dönmemek lazim
    .word	0x00000000 // replacing in stackallocate

    // handler prototype. being copied to sram stack to execute process function
GLOBAL_FUNCTION processHandler
    ldr r0, [pc, #8]
    ldr	r1, [pc, #12]
    blx	r1
    svc	1 // loop bitince napcaz kernel moda mi dönmek lazim ? buraya geri dönmemek lazim
    .word   0x00000000
    .word	0x00000000 // replacing in stackallocate
