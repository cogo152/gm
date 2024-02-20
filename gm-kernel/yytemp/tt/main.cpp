#include <stdio.h>

#include "exception.hpp"
#include "system.hpp"

#include <csignal>
#include <thread>

void configureExceptions(void)
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

void startSystem()
{
    if (!ST->STK_CTRL.enable_rw)
    {
        ST->STK_CTRL.enable_rw = 1;
    }
}

void signal_handler(int signal)
{
    printf("Signal %d \n", signal);
}

int b;

void signals()
{
    int *ptr = (int *)0xE00FFFFFF;
    *ptr = 0;

    int a = 3 / 0;
}

int main(void)
{
    printf("Program started\n");

    configureExceptions();

    // signals();

    return 0;
}