#ifndef RESET_HPP
#define RESET_HPP

struct reset_t
{
    unsigned ADC : 1;
    unsigned BUSCTRL : 1;
    unsigned DMA : 1;
    unsigned I2C0 : 1;
    unsigned I2C1 : 1;
    unsigned IO_BANK0 : 1;
    unsigned IO_QSPI : 1;
    unsigned JTAG : 1;
    unsigned PADS_BANK0 : 1;
    unsigned PADS_QSPI : 1;
    unsigned PIO0 : 1;
    unsigned PIO1 : 1;
    unsigned PLL_SYS : 1;
    unsigned PLL_USB : 1;
    unsigned PWM : 1;
    unsigned RTC : 1;
    unsigned SPI0 : 1;
    unsigned SPI1 : 1;
    unsigned SYSCFG : 1;
    unsigned SYSINFO : 1;
    unsigned TBMAN : 1;
    unsigned TIMER : 1;
    unsigned UART0 : 1;
    unsigned UART1 : 1;
    unsigned USBCTRL : 1;
    unsigned : 7;
};

class SubsystemResets
{
public:
    SubsystemResets(const SubsystemResets &) = delete;
    SubsystemResets &operator=(const SubsystemResets &) = delete;
    SubsystemResets(SubsystemResets &&) noexcept = delete;
    SubsystemResets &operator=(SubsystemResets &&) noexcept = delete;

    static SubsystemResets &instance()
    {
        static SubsystemResets instance{};
        return instance;
    }

    volatile reset_t &reset()
    {
        return reset_;
    }

    volatile reset_t &wdsel()
    {
        return wdsel_;
    }

    const volatile reset_t &resetDone() const
    {
        return resetDone_;
    }

private:
    SubsystemResets() : reset_(*reinterpret_cast<reset_t *>(0x4000f000U)),
                        wdsel_(*reinterpret_cast<reset_t *>(0x4000c004U)),
                        resetDone_(*reinterpret_cast<reset_t *>(0x4000c008U))
    {
    }

    ~SubsystemResets()
    {
    }

    volatile reset_t &reset_;
    volatile reset_t &wdsel_;
    volatile const reset_t &resetDone_;
};

#endif