extern "C" __attribute__((weak)) [[noreturn]] void _exit(int code)
{
    while (1)
        ;
}