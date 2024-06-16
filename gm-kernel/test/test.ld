MEMORY
{
    ROM(xr)     : ORIGIN = 0x00000000, LENGTH = 16K
    FLASH(xr)   : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM(xrw)    : ORIGIN = 0x20000000, LENGTH = 256K
}

INCLUDE /home/cogo152/Projects/gproject/gm/gm-kernel/source/sections.ld