    .syntax unified

    #include "common.h"

    .section .vector,"a"
    .type VectorTable, %object
VectorTable:
    .word  0
    .word  System_Handler
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

    ALIAS_FUNCTION  NMI_Handler
    ALIAS_FUNCTION  HardFault_Handler
    ALIAS_FUNCTION  MemManage_Handler
    ALIAS_FUNCTION  BusFault_Handler
    ALIAS_FUNCTION  UsageFault_Handler
    ALIAS_FUNCTION  DebugMon_Handler
    ALIAS_FUNCTION  PendSV_Handler
    ALIAS_FUNCTION  SysTick_Handler