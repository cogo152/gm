extern "C"
{
    void Start_Handler()
    {
        extern unsigned __data_load__;
        extern unsigned __data_start__;
        extern unsigned __data_end__;

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

    void Exit_Handler()
    {
        extern void _exit(int);

        _exit(99);
    }

    extern void Reserved() __attribute__((weak, alias("Exit_Handler"))); // delete later

    extern void NMI_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void HardFault_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void MemManage_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void BusFault_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void UsageFault_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void SVC_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void DebugMon_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void PendSV_Handler() __attribute__((weak, alias("Exit_Handler")));

    extern void SysTick_Handler() __attribute__((weak, alias("Exit_Handler")));
}

using void_func_t = void(void);

extern unsigned __msp_end__;

void_func_t *VectorTable[] __attribute__((section(".vectors"), used)){
    reinterpret_cast<void_func_t *>(&__msp_end__),
    Start_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    Reserved,
    Reserved,
    Reserved,
    Reserved,
    SVC_Handler,
    DebugMon_Handler,
    Reserved,
    PendSV_Handler,
    SysTick_Handler,
    // Add IRQs later. It can be device spesific
};
