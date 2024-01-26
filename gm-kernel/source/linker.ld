MEMORY
{
    FLASH(xr)   : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM(xrw)    : ORIGIN = 0x20000000, LENGTH = 256K
}

ENTRY(Start_Handler)

SECTIONS
{  

    .boot :
    {
        __boot_start__ = .;
        KEEP (*(.boot))
        __boot_end__ = .;
    } > FLASH

    .vectors :
    {     
        . = ALIGN(4);
        __vectors_start__ = .;
        KEEP (*(.vectors))
        . = ALIGN(4);
        __vectors_end__ = .;
    } > FLASH
        
    .text :
    {
        . = ALIGN(4);     
        __text_start__ = .;
        *(.text .text.*)
        . = ALIGN(4);
        __text_end__ = .;
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);     
        __rodata_start__ = .;
        *(.rodata .rodata.*)
        . = ALIGN(4);
        __rodata_end__ = .;
    } > FLASH

    .ARM.extab :
    {
        . = ALIGN(4);
        __extab_start = .;
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        . = ALIGN(4);
        __extab_end = .;
    } > FLASH

    .ARM.exidx :
    {
        . = ALIGN(4);
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        . = ALIGN(4);
        __exidx_end = .;
    } > FLASH

    .data :
    {
        __data_load__ = LOADADDR(.data);
        . = ALIGN(4);
        __data_start__ = .;
        *(.data .data.*)
        . = ALIGN(4);
        __data_end__ = .;
    }> RAM AT> FLASH

   .bss :
   {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
   } > RAM

}

__MSP = ORIGIN(RAM) + LENGTH(RAM);
__PSP = __MSP - 1K;

