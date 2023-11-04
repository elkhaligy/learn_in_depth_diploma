ENTRY(reset)

MEMORY
{
	big_mem (rwx): ORIGIN = 0x00000000, LENGTH = 64M
}
SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o (.text)
	}> big_mem
	.text :
	{
		*(.text) *(.rodata)
	}> big_mem
	.data :
	{
		*(.data)
	}> big_mem
	.bss :
	{
		*(.bss) *(COMMON)
	}> big_mem
	. = . + 0x1000; /* 4096 byte meaning 4KB of ram for the stack */
	stack_top = .;
}