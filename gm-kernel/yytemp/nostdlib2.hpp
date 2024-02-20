#ifndef NO_STD_LIB_HPP
#define NO_STD_LIB_HPP

#include <cstddef>
#include <cstdint>
#include <typeinfo>

extern "C"
{

    void __aeabi_unwind_cpp_pr0()
    {
    }

    void __aeabi_unwind_cpp_pr1()
    {
    }

    // Memory Management

    /*
        Effects:
            Allocates memory to hold the exception to be thrown.
            thrown_size is the size of the exception object.
            Can allocate additional memory to hold private data.
            If memory can not be allocated, call std::terminate().

        Returns:
            A pointer to the memory allocated for the exception object.
    */
    void *__cxa_allocate_exception(size_t thrownSize) throw()
    {
        extern void *_sbrk(ptrdiff_t);

        return _sbrk(thrownSize);
    }

    /*
        Effects:
            Frees memory allocated by __cxa_allocate_exception.
    */
    void __cxa_free_exception(void *thrownException) throw()
    {
    }

    /*
        Effects:
            Allocates memory to hold a "dependent" exception to be thrown.
            thrown_size is the size of the exception object.
            Can allocate additional memory to hold private data.
            If memory can not be allocated, call std::terminate().

        Returns:
            A pointer to the memory allocated for the exception object.
    */
    void *__cxa_allocate_dependent_exception() throw()
    {
        return nullptr;
    }

    /*
        Effects:
            Frees memory allocated by __cxa_allocate_dependent_exception.
    */
    void __cxa_free_dependent_exception(void *dependentException) throw()
    {
    }

    // Exception Handling

    void __cxa_throw(void *thrownException, void *typeInfo, void (*destination)(void *))
    // void __cxa_throw(void *thrownException, std::type_info *typeInfo, void (*destination)(void *))
    {
    }

    /*
        Returns:
            The adjusted pointer to the exception object.
            (The adjusted pointer is typically computed by the personality routine during phase 1 and saved in the exception object.)
    */
    void *__cxa_get_exception_ptr(void *exceptionObject) throw()
    {
        return nullptr;
    }

    /*
        Effects:
            Increment's the exception's handler count.
            Places the exception on the stack of currently-caught exceptions if it is not already there,
            linking the exception to the previous top of the stack.
            Decrements the uncaught_exception count.
            If the initialization of the catch parameter is trivial (e,g., there is no formal catch parameter,
            or the parameter has no copy constructor), the calls to __cxa_get_exception_ptr() and __cxa_begin_catch()
            may be combined into a single call to __cxa_begin_catch().
            When the personality routine encounters a termination condition,
            it will call __cxa_begin_catch() to mark the exception as handled and then call terminate(),
            which shall not return to its caller.

        Returns:
            The adjusted pointer to the exception object.
    */
    void *__cxa_begin_catch(void *exceptionObject) throw()
    {
        return nullptr;
    }

    /*
    Effects:
        Locates the most recently caught exception and decrements its handler count.
        Removes the exception from the caught exception stack, if the handler count goes to zero.
        Destroys the exception if the handler count goes to zero, and the exception was not re-thrown by throw.
        Collaboration between __cxa_rethrow() and __cxa_end_catch() is necessary to handle the last point.
        Though implementation-defined, one possibility is for __cxa_rethrow()
        to set a flag in the handlerCount member of the exception header to mark an exception being rethrown.
    */
    void __cxa_end_catch()
    {
    }

    /*
        Returns:
            the type of the currently handled exception, or null if there are no caught exceptions.
    */
    void *__cxa_current_exception_type()
    // std::type_info *__cxa_current_exception_type()
    {
        return nullptr;
    }

    /*
        Effects:
            Marks the exception object on top of the caughtExceptions stack (in an implementation-defined way) as being rethrown.
            If the caughtExceptions stack is empty, it calls terminate() (see [C++FDIS] [except.throw], 15.1.8).
            It then returns to the handler that called it, which must call __cxa_end_catch(), perform any necessary cleanup,
            and finally call _Unwind_Resume() to continue unwinding.
    */
    void __cxa_rethrow()
    {
    }

    /*
        Effects:
            Increments the ownership count of the currently handled exception (if any) by one.

        Returns:
            the type of the currently handled exception, or null if there are no caught exceptions.
    */
    void *__cxa_current_primary_exception() throw()
    {
        return nullptr;
    }

    /*
        Effects:
            Decrements the ownership count of the exception by 1, and on zero calls _Unwind_DeleteException with the exception object.
    */
    void __cxa_decrement_exception_refcount(void *primaryException) throw()
    {
    }

    /*
        Returns:
            A pointer to the __cxa_eh_globals structure for the current thread, initializing it if necessary.
    */
    void *__cxa_get_globals() throw()
    //__cxa_eh_globals *__cxa_get_globals() throw()
    {
        return nullptr;
    }

    /*
        Requires:
            At least one prior call to __cxa_get_globals has been made from the current thread.

        Returns:
            A pointer to the __cxa_eh_globals structure for the current thread.
    */
    void *__cxa_get_globals_fast() throw()
    //__cxa_eh_globals *__cxa_get_globals_fast() throw()
    {
        return nullptr;
    }

    /*
        Effects: Increments the ownership count of the referenced exception.
    */
    void __cxa_increment_exception_refcount(void *primaryException) throw()
    {
    }

    /*
        Effects: Implements std::rethrow_exception(exception_ptr p).
    */
    void __cxa_rethrow_primary_exception(void *primaryException)
    {
    }

    bool __cxa_uncaught_exception() throw()
    {
        return false;
    }

    int __gxx_personality_v0(int, int, int, void *, void *)
    //_Unwind_Reason_Code __gxx_personality_v0(int, _Unwind_Action, _Unwind_Exception_Class, struct _Unwind_Exception *, struct _Unwind_Context *)
    {
        return 0;
    }

    // Guard Objects

    /*
        Effects:
            This function is called before initialization takes place.
            If this function returns 1, either __cxa_guard_release or __cxa_guard_abort must be called with the same argument.
            The first byte of the guard_object is not modified by this function.
            On Darwin the implementation checks for deadlock.

        Returns:
            1 if the initialization is not yet complete, otherwise 0.

    */
    int __cxa_guard_acquire(uint64_t *guardObject)
    {
        return 0;
    }

    /*
        Effects:
            Sets the first byte of the guard object to a non-zero value.
            This function is called after initialization is complete.
            A thread-safe implementation will release the mutex acquired by __cxa_guard_acquire after setting the first byte of the guard object.
    */
    void __cxa_guard_release(uint64_t *guardObject)
    {
    }

    /*
        Effects:
        This function is called if the initialization terminates by throwing an exception.
    */
    void __cxa_guard_abort(uint64_t *guardObject)
    {
    }

    // Vector Construction and Destruction

    // Handlers

    /*
        The currently installed new handler.
    void (*__cxa_new_handler)()
    {
    }
    */

    /*
        The currently installed terminate handler.
    void (*__cxa_terminate_handler)()
    {
    }
     */

    /*
       void (*__cxa_unexpected_handler)()
       {
       }
       */

    // Utilities

    /*
        Effects:
            Throws an exception of type bad_cast.
    */
    [[noreturn]] void __cxa_bad_cast()
    {
    }

    /*
        Effects:
            Throws an exception of type bad_typeid.
    */
    [[noreturn]] void __cxa_bad_typeid()
    {
    }

    /*
    Effects:
        Called if the user calls a non-overridden pure virtual function, which has undefined behavior according to the C++ Standard.
        Ends the program.
    */
    void __cxa_pure_virtual(void)
    {
    }

    /*
    Effects:
        Handles re-checking the exception specification if unexpectedHandler throws, and if bad_exception needs to be thrown.
        Called from the compiler.
    */
    __attribute__((noreturn)) void __cxa_call_unexpected(void *)
    {
    }

    char *__cxa_demangle(const char *mangledName, char *outputBuffer, size_t *length, int *status)
    {
        return nullptr;
    }

    void *__dynamic_cast(const void *__src_ptr, const void *__src_type, const void *__dst_type, ptrdiff_t __src2dst)
    // void *__dynamic_cast(const void *__src_ptr, const __class_type_info *__src_type, const __class_type_info *__dst_type, ptrdiff_t __src2dst)
    {
        return nullptr;
    }
};

#endif