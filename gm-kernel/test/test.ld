MEMORY
{
    FLASH(xr)   : ORIGIN = 0x00000000, LENGTH = 512K
    RAM(xrw)    : ORIGIN = 0x20000000, LENGTH = 64K
}

INCLUDE /home/cogo152/Projects/gproject/gm/gm-kernel/source/sections.ld