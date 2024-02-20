    .syntax unified

    #include "common.h"

    .section .vector,"a"
    .type VectorTable, %object
VectorTable:
    .word  0x00000000
    .word  Start_Handler
    .word  NMI_Handler
    .word  HardFault_Handler
    .word  MemManage_Handler
    .word  BusFault_Handler
    .word  UsageFault_Handler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  SVC_Handler
    .word  DebugMon_Handler
    .word  0
    .word  PendSV_Handler
    .word  SysTick_Handler

    VECTOR_FUNCTION  NMI_Handler
    VECTOR_FUNCTION  HardFault_Handler
    VECTOR_FUNCTION  MemManage_Handler
    VECTOR_FUNCTION  BusFault_Handler
    VECTOR_FUNCTION  UsageFault_Handler
    VECTOR_FUNCTION  DebugMon_Handler