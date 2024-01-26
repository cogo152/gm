#ifndef CORE_H
#define CORE_H

#include "common.h"

#define MSP_ACTIVE (0 << 1)
#define PSP_ACTIVE (1 << 1)

#define FPU_ACTIVE (1 << 2)
#define FPU_NONACTIVE (0 << 2)

#define THREAD_PRIVILEGED (0 << 0)
#define THREAD_UNPRIVILEGED (1 << 0)

#define KERNEL_MODE (FPU_NONACTIVE | MSP_ACTIVE | THREAD_PRIVILEGED)
#define USER_MODE (FPU_NONACTIVE | PSP_ACTIVE | THREAD_UNPRIVILEGED)

#ifdef __ASSEMBLER__

.extern set_MSP
.extern get_MSP
.extern set_PSP
.extern get_PSP
.extern set_Mode

#else

extern void set_MSP(uint32_t mspValue);
extern uint32_t get_MSP(void);
extern void set_PSP(uint32_t mspValue);
extern uint32_t get_PSP(void);
extern void set_Mode(uint32_t modeValue);

#endif

#endif // CORE_H
