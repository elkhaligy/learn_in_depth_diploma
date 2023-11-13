/*
*	linker_script.ld
*	Created on: 6 Nov 23
*	Author: Shehab Elkhaligy
*/
MEMORY
{
	FLASH(RX): ORIGIN = 0x00000000, LENGTH = 512M
	SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	/*This file is space sensitive, be careful*/
	.text : {
		*(.vectors*) /*This means take any sections called .vectors in any object file you see*/
		*(.text*)
		*(.rodata)
		_E_Text = .;
		. = ALIGN(4);
	}> FLASH

	.data : {
		_S_Data = .;
		*(.data) /*This means from every .o file pick up the .data section*/
		*(.data.*) /*Put anything .data.anything in .data section*/
		_E_Data = .;
		. = ALIGN(4);
	}> SRAM AT> FLASH /*Load address= FLASH, Runtime address= RAM*/

	.bss : {
		_S_Bss = .;
		*(.bss)
		*(.bss.*) /*put anything .bss.anything in .bss section*/
		_E_Bss = .; /* if bss ended at x2005 the . will be 0x2006 */
		. = ALIGN(4);
		. = . + 0x1000;
		_Heap_End = .;
		. = ALIGN(4);
		. = . + 0x1000;
		_Stack_Top = .;
	}> SRAM
}