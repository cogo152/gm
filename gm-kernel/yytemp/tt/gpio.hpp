#ifndef GPIO_HPP
#define GPIO_HPP

#include "base.hpp"

namespace gpio
{
    enum class pin_e : unsigned
    {
        PIN_0 = 0,
        PIN_1,
        PIN_2,
        PIN_3,
        PIN_4,
        PIN_5,
        PIN_6,
        PIN_7,
        PIN_8,
        PIN_9,
        PIN_10,
        PIN_11,
        PIN_12,
        PIN_13,
        PIN_14,
        PIN_15,
        PIN_16,
        PIN_17,
        PIN_18,
        PIN_19,
        PIN_20,
        PIN_21,
        PIN_22,
        PIN_23,
        PIN_24,
        PIN_25,
        PIN_26,
        PIN_27,
        PIN_28,
        PIN_29
    };

    enum class pin_function_e : unsigned char
    {
        F1 = 1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9
    };

    class OutputPin
    {
    public:
        constexpr OutputPin(pin_e pin) : pin(pin),
                                         status(getStatusOffest()),
                                         ctrl(getCtrlOffest()),
                                         ouEnableSet(getOuEnableSet()),
                                         ouSet(getOuSet()),
                                         ouClr(getOuClr()),
                                         sioData(getSioData())

        {
            volatile unsigned *ptr = reinterpret_cast<unsigned *>(ctrl);
            *ptr = static_cast<unsigned>(pin_function_e::F5);

            ptr = reinterpret_cast<unsigned *>(ouEnableSet);
            *ptr = sioData;
        }

        constexpr void set() const
        {
            volatile unsigned *ptr = reinterpret_cast<unsigned *>(ouSet);
            *ptr = sioData;
        }

        constexpr void clear() const
        {
            volatile unsigned *ptr = reinterpret_cast<unsigned *>(ouClr);
            *ptr = sioData;
        }

    private:
        const pin_e pin;

        const unsigned status;
        const unsigned ctrl;
        const unsigned ouEnableSet;
        const unsigned ouSet;
        const unsigned ouClr;

        const unsigned sioData;

        constexpr unsigned getStatusOffest()
        {
            unsigned offset = static_cast<unsigned>(pin);
            offset *= 8U, offset += base::IO_BANK0_BASE;
            return offset;
        }

        constexpr unsigned getCtrlOffest()
        {
            return getStatusOffest() + 4U;
        }

        constexpr unsigned getOuEnableSet()
        {
            return 0x024U + base::SIO_BASE;
        }

        constexpr unsigned getOuSet()
        {
            return 0x014U + base::SIO_BASE;
        }

        constexpr unsigned getOuClr()
        {
            return 0x018U + base::SIO_BASE;
        }

        constexpr unsigned getSioData()
        {
            return 1 << static_cast<unsigned>(pin);
        }
    };

} // namespace gpio

#endif

/*

 ctlOffset(0x40014000U + 0x07cU),
                      ouEnableSetOffset(0xd0000000U + 0x024U),
                      ouSetOffset(0xd0000000U + 0x014U),
                      ouClrOffset(0xd0000000U + 0x018U),
                      sioData(1 << 15U)
*/