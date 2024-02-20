#include "common.h"
 
    .section .vectors,"a"
    .global VectorTable
    .type VectorTable,%object
VectorTable:
    .word  __StackTop
    .word  Start_Handler
    .word  NMI_Handler
    .word  HardFault_Handler
    .word  MemManage_Handler
    .word  BusFault_Handler
    .word  UsageFault_Handler
    .word  0x00000000
    .word  0x00000000
    .word  0x00000000
    .word  0x00000000
    .word  SVC_Handler
    .word  DebugMon_Handler
    .word  0x00000000
    .word  PendSV_Handler
    .word  SysTick_Handler
    
    DEFAULT_HANDLER  NMI_Handler
    DEFAULT_HANDLER  HardFault_Handler
    DEFAULT_HANDLER  MemManage_Handler
    DEFAULT_HANDLER  BusFault_Handler
    DEFAULT_HANDLER  UsageFault_Handler
    DEFAULT_HANDLER  SVC_Handler
    DEFAULT_HANDLER  DebugMon_Handler
    DEFAULT_HANDLER  PendSV_Handler
    DEFAULT_HANDLER  SysTick_Handler