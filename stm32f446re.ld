/* Minimal linker file for stm32f446re microcontroller */

ENTRY(Reset_Handler)

_estack = ORIGIN(RAM) + LENGTH(RAM);

_Min_Heap_Size = 0x200;
_Min_Stack_Size = 0x400;

MEMORY
{
    RAM(xrw)  : ORIGIN = 0x20000000, LENGTH = 128K
    FLASH(rw) : ORIGIN = 0x08000000, LENGTH = 512K
}

SECTIONS
{
    .text : {
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } >FLASH

    .data : {
		_sdata = .;
		*(.data*)
		*(.ramtext*)
		. = ALIGN(4);
		_edata = .;
	} >RAM AT >FLASH
	_data_loadaddr = LOADADDR(.data);

    .bss  : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
		. = ALIGN(4);
		_ebss = .;
    } >RAM
}