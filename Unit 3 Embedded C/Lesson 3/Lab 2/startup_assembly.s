/*
*	startup_cortex_m3.s
*	Created on: 6 Nov 23
*	Author: Shehab Elkhaligy
*/

/* This .section tells the assembler to create a .vectors section for the following symbols*/
.section .vectors
.word 0x20001000
.word _reset /*_reset is a symbol and any symbol is given an address by the linker*/
.word Vector_Handler
.word Vector_Handler



/* Below is assembly code -> goes to .text section*/
.section .text /* just to make sure assembler doesn't count them with .vectors */
_reset:
	bl main
	b .

.thumb_func
Vector_Handler:
	b _reset