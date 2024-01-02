#ifndef COMMON_H
#define COMMON_H

#define HIGH    (0X01U)
#define LOW     (0x00U)

#ifdef __ASSEMBLER__

.macro GLOBAL_FUNCTION globalFunction
    .text
    .align 2
    .thumb
    .thumb_func
    .global \globalFunction  
    .type \globalFunction,% function
    \globalFunction :
.endm

.macro STATIC_FUNCTION staticFunction
    .text
    .align 2
    .thumb
    .thumb_func
    .type \staticFunction,% function
    \staticFunction :
.endm

.macro WEAK_FUNCTION weakFunction
    .text
    .align 2
    .thumb
    .thumb_func   
    .global \weakFunction
    .weak \weakFunction
    .type \weakFunction,% function
    \weakFunction :
.endm

.macro ALIAS_FUNCTION vectorFunction
    .weak \vectorFunction
    .thumb_set \vectorFunction, Alias_Vector_Handler
.endm

#else

#include <stddef.h>
#include <stdint.h>

typedef void (* voidFunctionPointer)(void );
typedef void (* parameterFunctionPointer)(void *);

#endif // __ASSEMBLER__

#endif // COMMON_H
