#include <gctest/core/test.hpp>

#include <iostream>

#include "system.hpp"
#include "exception.hpp"

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

GCTEST_SUIT_NAME(gm kernel test);

GCTEST_SUIT_ADD_START_COMMAND(startCommand1, 1)
{
    configureExceptions();
    std::cout << " Exceptions Configured " << std::endl;
}
