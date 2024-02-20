#include "common.h"
#include "core_cpu.h"
#include "system.h"

GLOBAL_FUNCTION Start_Handler
    
	ldr	r1, =__data_load__
	ldr	r2, =__data_start__
	ldr	r3, =__data_end__
	subs	r3, r2
	ble	.L_loop1_done
.L_loop1:
	subs	r3, #4
	ldr	r0, [r1,r3]
	str	r0, [r2,r3]
	bgt	.L_loop1
.L_loop1_done:

	ldr	r1, =__bss_start__
	ldr	r2, =__bss_end__
	movs	r0, 0
	subs	r2, r1
	ble	.L_loop3_done
.L_loop3:
	subs	r2, #4
	str	r0, [r1, r2]
	bgt	.L_loop3
.L_loop3_done:

	bl system_start

	bl _start 

	bl _stop

	bl system_stop

	b halt

// unprivillaged
WEAK_FUNCTION _start
	push {lr}
	bl main
	pop {pc}

// unprivillaged
WEAK_FUNCTION _stop
	push {lr}
	pop {pc}

GLOBAL_FUNCTION Stop_Handler
	b .

// must be in privilaged thread mode
halt :
	//wfe
	b .