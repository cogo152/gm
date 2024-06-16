#include "system.hpp"

#define PRIORITY_0 (0X00U)
#define PRIORITY_1 (0X01U)
#define PRIORITY_2 (0X02U)
#define PRIORITY_3 (0X03U)

#define HANDLER_NOFPU_MSP (0xFFFFFFF1U)
#define HANDLER_FPU_MSP (0xFFFFFFE1U)
#define THREAD_FPU_MSP (0xFFFFFFE9U)
#define THREAD_FPU_PSP (0xFFFFFFEDU)
#define THREAD_NOFPU_MSP (0xFFFFFFF9U)
#define THREAD_NOFPU_PSP (0xFFFFFFFDU)

#define SCB ((volatile struct SCB_t *)(0xE000ED00))
#define ST ((volatile struct ST_t *)(0xE000E010))

void configure_exceptions(void)
{
    SCB->SHCSR.usgFaultEna_rw = 1;
    SCB->SHCSR.busFaultEna_rw = 1;
    SCB->SHCSR.memFaultEna_rw = 1;

    SCB->SHPR1.memManFault_rw = PRIORITY_0;
    SCB->SHPR1.busFault_rw = PRIORITY_0;
    SCB->SHPR1.memManFault_rw = PRIORITY_0;
    SCB->SHPR3.sysTick_rw = PRIORITY_1;
    SCB->SHPR2.svcCall_rw = PRIORITY_2;
    SCB->SHPR3.pendSV_rw = PRIORITY_3;

    ST->STK_VAL.currentValue_rw = 0x00;
    ST->STK_LOAD.reloadValue_rw = DEFAULT_PROCESS_SWITCH;

    ST->STK_CTRL.clockSource_rw = CLOCK_SOURCE_AHB;
    ST->STK_CTRL.tickInt_rw = 1;
}
