MEMORY{
	FLASH(rx) : ORIGIN = 0X08000000, LENGTH = 64K
	SRAM(rwx) : ORIGIN = 0X20000000, LENGTH = 20K
}


SECTIONS{
	.text : ALIGN(4)
	{
		*(.isr_vector)
		*(.text)
		KEEP(*(.isr_vector))
	} >FLASH
	
	.rodata : ALIGN(4)
	{
		. = ALIGN(4);
		*(.rodata)
		. = ALIGN(4);
	} >FLASH
	
	_sidata = LOADADDR(.data);

	.data : ALIGN(4) 
	{
		. = ALIGN(4);
		_sdata = ABSOLUTE(.) ;

		*(.data)

		. = ALIGN(4);
		_edata = ABSOLUTE(.) ;

	} >SRAM  AT>FLASH

	.bss : ALIGN(4)
	{
		. = ALIGN(4);
		_sbss = ABSOLUTE(.) ;

		*(.bss)
		*(COMMON)

		. = ALIGN(4);
		_ebss = ABSOLUTE(.) ;

	} >SRAM AT>SRAM

	_sheap = _ebss;
	_heap_size = 0x800;
	_eheap = _sheap + _heap_size;
}

