#ifndef NO_STD_LIB_HPP
#define NO_STD_LIB_HPP

#include <cstddef>
#include <cstdint>
#include <cstdlib>

extern "C"
{

    void *__cxa_begin_catch(void *) noexcept
    {
        return nullptr;
    }

    __attribute__((weak)) void __cxa_end_catch()
    {
    }

    __attribute__((weak)) void *__cxa_allocate_exception(size_t thrownSize) throw()
    {
        extern void *_sbrk(ptrdiff_t);

        return _sbrk(thrownSize);
    }

    __attribute__((weak)) void __cxa_throw(void *thrownException, void *typeInfo, void (*destination)(void *))
    {
    }

    __attribute__((weak)) void __gxx_personality_v0()
    {
    }

    __attribute__((weak)) void __aeabi_unwind_cpp_pr0()
    {
    }

    __attribute__((weak)) void __aeabi_unwind_cpp_pr1()
    {
    }
};

#endif