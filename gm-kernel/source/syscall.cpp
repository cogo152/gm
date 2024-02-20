#ifndef SEMIHOST

extern "C"
{

/* Includes */
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

#include <stddef.h>

    extern unsigned __heap_start__;
    extern unsigned __heap_end__;

    /* Variables */
    // #undef errno
    extern int errno;
    extern int __io_putchar(int ch) __attribute__((weak));
    extern int __io_getchar(void) __attribute__((weak));

    char *__env[1] = {0};
    char **environ = __env;

    __attribute__((weak)) void _exit(int status)
    {
    }

    __attribute__((weak)) int _getpid(void)
    {
        return 1;
    }

    __attribute__((weak)) int _kill(int pid, int sig)
    {
        errno = EINVAL;
        return -1;
    }

    __attribute__((weak)) int _read(int file, char *ptr, int len)
    {
        int DataIdx;

        for (DataIdx = 0; DataIdx < len; DataIdx++)
        {
            *ptr++ = __io_getchar();
        }

        return len;
    }

    __attribute__((weak)) int _write(int file, char *ptr, int len)
    {
        int DataIdx;

        for (DataIdx = 0; DataIdx < len; DataIdx++)
        {
            __io_putchar(*ptr++);
        }
        return len;
    }

    __attribute__((weak)) int _close(int file)
    {
        return -1;
    }

    __attribute__((weak)) int _isatty(int file)
    {
        return 1;
    }

    __attribute__((weak)) int _lseek(int file, int ptr, int dir)
    {
        return 0;
    }

    __attribute__((weak)) int _open(char *path, int flags, ...)
    {
        return -1;
    }

    __attribute__((weak)) int _wait(int *status)
    {
        errno = ECHILD;
        return -1;
    }

    __attribute__((weak)) int _unlink(char *name)
    {
        errno = ENOENT;
        return -1;
    }

    __attribute__((weak)) int _times(struct tms *buf)
    {
        return -1;
    }

    __attribute__((weak)) int _stat(char *file, struct stat *st)
    {
        st->st_mode = S_IFCHR;
        return 0;
    }

    __attribute__((weak)) int _link(char *old, char *_new)
    {
        errno = EMLINK;
        return -1;
    }

    __attribute__((weak)) int _fork(void)
    {
        errno = EAGAIN;
        return -1;
    }

    __attribute__((weak)) int _execve(char *name, char **argv, char **env)
    {
        errno = ENOMEM;
        return -1;
    }

    __attribute__((weak)) void *_sbrk(ptrdiff_t increament)
    {
        static char *heapLast = reinterpret_cast<char *>(&__heap_start__);
        register char *stackPointer asm("sp");

        char *heapToReturn = heapLast;

        if (heapLast += increament, heapLast > stackPointer)
        {
            heapLast -= increament;
            errno = ENOMEM;
            return reinterpret_cast<char *>(-1);
        }

        return heapToReturn;
    }

    __attribute__((weak)) int _fstat(int file, struct stat *st)
    {
        st->st_mode = S_IFCHR;
        return 0;
    }
};

#endif