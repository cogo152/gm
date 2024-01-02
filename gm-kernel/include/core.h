#ifndef CORE_H
#define CORE_H

#include "common.h"

#define MSP_ACTIVE (0 << 1)
#define PSP_ACTIVE (1 << 1)

#define THREAD_PRIVILEGED (0 << 0)
#define THREAD_UNPRIVILEGED (1 << 0)

#define CORE_MODE_KERNEL (PSP_ACTIVE | THREAD_PRIVILEGED)
#define CORE_MODE_USER (PSP_ACTIVE | THREAD_UNPRIVILEGED)

#define CORE_HANDLER_MSP_NOFPU (0xFFFFFFF1U)
#define CORE_THREAD_MSP_NOFPU (0xFFFFFFF9U)
#define CORE_THREAD_PSP_NOFPU (0xFFFFFFFDU)

#ifdef __ASSEMBLER__

.extern core_msp_set
.extern core_msp_get
.extern core_psp_set
.extern core_psp_get
.extern core_mode_set

#else

extern void core_msp_set(uint32_t mspValue);
extern uint32_t core_msp_get(void);
extern void core_psp_set(uint32_t mspValue);
extern uint32_t core_psp_get(void);
extern void core_mode_set(uint32_t modeValue);

#endif

#endif // CORE_H
