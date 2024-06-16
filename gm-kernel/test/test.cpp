int main()
{
    extern void configure_exceptions();

    configure_exceptions();

    unsigned *ptr = reinterpret_cast<unsigned *>(0);

    unsigned data = 2/0;

    *ptr = 0;

    data = *ptr;
}
