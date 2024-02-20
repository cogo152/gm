#include "cpu.hpp"

#include <stdio.h>

using void_func_t = void(void);

extern unsigned __msp_end__;
extern unsigned __psp_end__;

extern unsigned __data_load__;
extern unsigned __data_start__;
extern unsigned __data_end__;

extern unsigned __bss_start__;
extern unsigned __bss_end__;

extern void_func_t *__preinit_array_start[];
extern void_func_t *__preinit_array_end[];

extern void_func_t *__init_array_start[];
extern void_func_t *__init_array_end[];

extern void_func_t *__fini_array_start[];
extern void_func_t *__fini_array_end[];

extern int main();

#include <csignal>

extern "C"
{
    __attribute__((weak)) void _start()
    {
        auto *bssStart = &__bss_start__;
        auto *bssEnd = &__bss_end__;
        while (bssStart < bssEnd)
        {
            *bssStart++ = 0;
        }

        auto arrayStart = __preinit_array_start;
        auto arrayEnd = __preinit_array_end;
        while (arrayStart < arrayEnd)
        {
            (*arrayStart++)();
        }

        arrayStart = __init_array_start;
        arrayEnd = __init_array_end;
        while (arrayStart < arrayEnd)
        {
            (*arrayStart++)();
        }

        int status = main();

        arrayStart = __fini_array_start;
        arrayEnd = __fini_array_end;
        while (arrayStart < arrayEnd)
        {
            (*arrayStart++)();
        }

        void _exit(int);
        _exit(status);
    }

    __attribute__((naked)) void Start_Handler()
    {
        auto *dataLoad = &__data_load__;
        auto *dataStart = &__data_start__;
        auto *dataEnd = &__data_end__;
        while (dataStart < dataEnd)
        {
            *dataStart++ = *dataLoad++;
        }

        void _start();

        _start();
    }

    void NMI_Handler()
    {
        printf("NMI_Handler \n");
        std::raise(SIGKILL);
    }

    void HardFault_Handler()
    {
        printf("HardFault_Handler \n");
        std::raise(SIGKILL);
    }

    void MemManage_Handler()
    {
        printf("MemManage_Handler \n");
        std::raise(SIGKILL);
    }

    void BusFault_Handler()
    {
        printf("BusFault_Handler \n");
        std::raise(SIGKILL);
    }

    void UsageFault_Handler()
    {
        printf("UsageFault_Handler \n");
        std::raise(SIGKILL);
    }
    void SVC_Handler()
    {
        printf("SVC_Handler \n");
    }

    void DebugMon_Handler()
    {
        printf("DebugMon_Handler \n");
        std::raise(SIGKILL);
    }

    void PendSV_Handler()
    {
        printf("PendSV_Handler \n");
    }

    void SysTick_Handler(void)
    {
        printf("SysTick_Handler \n");
    }

    void Exit_Handler()
    {
        printf("Exit_Handler \n");
        while (true)
            ;
    }
}

static void_func_t *VectorTable[] __attribute__((section(".vectors"), used)){
    reinterpret_cast<void_func_t *>(&__msp_end__),
    Start_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    Exit_Handler,
    Exit_Handler,
    Exit_Handler,
    Exit_Handler,
    SVC_Handler,
    DebugMon_Handler,
    Exit_Handler,
    PendSV_Handler,
    SysTick_Handler,
};
