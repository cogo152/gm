ENTRY(Start_Handler)

SECTIONS
{ 

    .flash :
    {
                
        KEEP (*(.boot))

        KEEP (*(.vectors))

        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))

	/* .ctors */
	*crtbegin.o(.ctors)
	*crtbegin?.o(.ctors)
	/**(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)*/
	*(SORT(.ctors.*))
	*(.ctors)

	/* .dtors */
 	*crtbegin.o(.dtors)
 	*crtbegin?.o(.dtors)
 	/**(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)*/
 	*(SORT(.dtors.*))
 	*(.dtors)
		
	*(.rodata*)

	KEEP(*(.eh_frame*))

	*(.ARM.extab* .gnu.linkonce.armextab.*)

        __exidx_start = .;
	
	*(.ARM.exidx* .gnu.linkonce.armexidx.*)

	__exidx_end = .;

	*(.glue_7*)

    } > FLASH AT > FLASH

    .flash_to_ram : ALIGN(4)
    {
        __data_load__ = LOADADDR(.flash_to_ram);

        __data_start__ = .;

	*(vtable)

        *(.data*)

	. = ALIGN(4);
	/* preinit data */
	PROVIDE_HIDDEN (__preinit_array_start = .);
	KEEP(*(.preinit_array))
	PROVIDE_HIDDEN (__preinit_array_end = .);

	. = ALIGN(4);
	/* init data */
	PROVIDE_HIDDEN (__init_array_start = .);
	KEEP(*(SORT(.init_array.*)))
	KEEP(*(.init_array))
	PROVIDE_HIDDEN (__init_array_end = .);

	. = ALIGN(4);
	/* finit data */
	PROVIDE_HIDDEN (__fini_array_start = .);
	KEEP(*(SORT(.fini_array.*)))
	KEEP(*(.fini_array))
	PROVIDE_HIDDEN (__fini_array_end = .);

	KEEP(*(.jcr*))

        . = ALIGN(4);

        __data_end__ = .;

    } > RAM AT > FLASH

   .ram : ALIGN(4)
   {
        __bss_start__ = .;

        *(.bss*)

        *(COMMON)

        . = ALIGN(4);

        __bss_end__ = .;

   } > RAM AT > RAM

	.heap (COPY):
	{
	__end__ = .;

	PROVIDE(end = .);
		
	__heap_start__ = .;

	*(.heap*)

	__heap_end__ = .;
		
	} > RAM AT > RAM

	/* .stack section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack (COPY):
	{

		*(.stack*)

	} > RAM AT > RAM

	__msp_end__ = ORIGIN(RAM) + LENGTH(RAM);
	__msp_start__ = __msp_end__ - 4K;

	/* Set stack top to end of RAM, and stack limit move down by
	 * size of stack_dummy section */
	__psp_end__ = __msp_start__;
	__psp_start__ = __psp_end__ - SIZEOF(.stack);
	
	/* Check if data + heap + stack exceeds RAM limit */
	/*ASSERT(__psp_start__ >= __heap_end__, "region RAM overflowed with stack")*/

	PROVIDE(__stack = __psp_end__);
  
}

