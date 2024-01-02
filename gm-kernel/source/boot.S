	.syntax	unified

	#include "common.h"
	#include "core_cpu.h"
	#include "system.h"
	#include "syscall.h"
	
	.section .stack
	.align	3
#ifdef __STACK_SIZE
	.equ	Stack_Size, __STACK_SIZE
#else
	.equ	Stack_Size, 0xc00
#endif
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap
	.align	3
#ifdef __HEAP_SIZE
	.equ	Heap_Size, __HEAP_SIZE
#else
	.equ	Heap_Size, 0
#endif
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
	.if	Heap_Size
	.space	Heap_Size
	.endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit


// System_Handler block

GLOBAL_FUNCTION System_Handler

    ldr r0, = __MSP
    bl cpu_msp_set // Load kernel sp

	ldr r0, = __PSP
	bl cpu_psp_set // Load user sp

	movs r0, #0x2 
	msr control, r0
    isb // use psp and flash

	// copy data
	ldr	r1, =__etext
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

	// zero bss
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

	svc #SVC_SYSTEM_START

	bl _start 

	bl _stop

	svc #SVC_SYSTEM_STOP

	b halt

// unprivillaged
WEAK_FUNCTION _start
	push {lr}
	bl main
	pop {pc}

// unprivillaged
WEAK_FUNCTION _stop
	nop
	bx lr

// must be in privilaged thread mode
halt :
	b .

GLOBAL_FUNCTION Alias_Vector_Handler
	b .
	
