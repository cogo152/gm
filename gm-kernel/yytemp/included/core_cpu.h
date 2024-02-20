#ifndef CORE_H
#define CORE_H

#include "common.h"

#define CPU_MSP_ACTIVE (0 << 1)
#define CPU_PSP_ACTIVE (1 << 1)

#define CPU_THREAD_PRIVILEGED (0 << 0)
#define CPU_THREAD_UNPRIVILEGED (1 << 0)

#define CPU_MODE_KERNEL (CPU_PSP_ACTIVE | CPU_THREAD_PRIVILEGED)
#define CPU_MODE_USER (CPU_PSP_ACTIVE | CPU_THREAD_UNPRIVILEGED)

#define CPU_EXC_RETURN_HANDLER_MSP_NOFPU (0xFFFFFFF1U)
#define CPU_EXC_RETURN_THREAD_MSP_NOFPU (0xFFFFFFF9U)
#define CPU_EXC_RETURN_THREAD_PSP_NOFPU (0xFFFFFFFDU)

#ifdef __ASSEMBLER__

.extern cpu_msp_set
.extern cpu_msp_get
.extern cpu_psp_set
.extern cpu_psp_get
.extern cpu_mode_set
.extern cpu_mode_get

#else

extern void core_msp_set(uint32_t mspValue);
extern uint32_t core_msp_get(void);
extern void core_psp_set(uint32_t mspValue);
extern uint32_t core_psp_get(void);
extern void core_mode_set(uint32_t modeValue);
extern uint32_t cpu_mode_get(void);

#endif

#endif // CORE_H
