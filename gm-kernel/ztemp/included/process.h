#ifndef PROCESS_H
#define PROCESS_H

#include "common.h"
#include "memory.h"

#ifdef __ASSEMBLER__

.extern saveContext
    .extern retrieveContext
    .extern startProcessContext

#else

struct process_t
{
    uint8_t id;
    uint8_t priority;
    struct stack_t stack;
    struct process_t *previous;
    struct process_t *next;
};

extern void configureProcessContext(void);

extern void createProcess(uint32_t stackSize,
                          struct process_t *process,
                          voidFunctionPointer handlerFunction,
                          uint8_t handlerSize,
                          parameterFunctionPointer function,
                          void *functionArguments,
                          uint8_t priority);

extern void createMainProcess(uint32_t stackSize,
                              struct process_t *process,
                              voidFunctionPointer handlerFunction,
                              uint8_t handlerSize,
                              voidFunctionPointer function,
                              uint8_t priority);

extern uintptr_t saveContext();

extern uintptr_t retrieveContext(uintptr_t currentStack);

extern void startProcessContext(void);

#endif

#endif // PROCESS_H
