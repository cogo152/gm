#include "common.h"

#define GPIO_D_BASE (0x40020C00U)
#define GPIO_BSRR (GPIO_D_BASE + 0x18)
#define _GPIO_SET_12 (1 << 12)
#define _GPIO_CLR_12 (1 << 28)

int global = 5;

void init();
void destroy();
void set_GPIOD_12();
void clr_GPIOD_12();
void sleep();

void set_GPIOD_12()
{
    uintptr_t *ptr = (uintptr_t *)GPIO_BSRR;
    *ptr |= _GPIO_SET_12;
}

void clr_GPIOD_12()
{
    uintptr_t *ptr = (uintptr_t *)GPIO_BSRR;
    *ptr |= _GPIO_CLR_12;
}

void sleep()
{
    int sleep = 0;

    const uint32_t sleepTime = 100000;

    for (uint32_t i = 0; i < sleepTime; i++)
    {
        ++sleep;
        ++global;
    }
}

int main()
{

    for (size_t i = 0; i < 10; i++)
    {
        set_GPIOD_12();
        sleep();
        clr_GPIOD_12();
        sleep();
    }

    return 0;
}