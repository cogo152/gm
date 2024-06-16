#include <cstdio>
#include <csignal>

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

extern "C" void __attribute__((naked)) Start_Handler()
{
    auto *dataLoad = &__data_load__;
    auto *dataStart = &__data_start__;
    auto *dataEnd = &__data_end__;
    while (dataStart < dataEnd)
    {
        *dataStart++ = *dataLoad++;
    }

    extern void _start();

    _start();
}

extern "C" void NMI_Handler()
{
    printf("NMI_Handler \n");
    std::raise(SIGKILL);
}

extern "C" void HardFault_Handler()
{
    printf("HardFault_Handler \n");
    std::raise(SIGKILL);
}

extern "C" void MemManage_Handler()
{
    printf("MemManage_Handler \n");
    std::raise(SIGKILL);
}

extern "C" void BusFault_Handler()
{
    printf("BusFault_Handler \n");
    std::raise(SIGKILL);
}

extern "C" void UsageFault_Handler()
{
    printf("UsageFault_Handler \n");
    std::raise(SIGKILL);
}
extern "C" void SVC_Handler()
{
    printf("SVC_Handler \n");
}

extern "C" void DebugMon_Handler()
{
    printf("DebugMon_Handler \n");
    std::raise(SIGKILL);
}

extern "C" void PendSV_Handler()
{
    printf("PendSV_Handler \n");
}

extern "C" void SysTick_Handler(void)
{
    printf("SysTick_Handler \n");
}

extern "C" void Exit_Handler()
{
    while (true)
        ;
}