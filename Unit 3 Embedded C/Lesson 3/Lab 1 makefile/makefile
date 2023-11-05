#Author: Shehab Elkhaligy
# $< means dependency
# $@ means target
# % is generic type
# $(wildcard *(file_extension)) is used to gather all the files with specific extension in a variable
# $((VAR):(file_extension_1)=(file_extension_2)) is used to convert something like uart.c to uart.o

CPU		= arm926ej-s
CC		= arm-none-eabi-
CFLAGS	= -g -mcpu=$(CPU)
INCS	= -I inc
LIBS	=
SRC 	= $(wildcard src/*.c)
OBJ 	= $(SRC:.c=.o)
AS_SRC	= $(wildcard *.s)
AS_OBJ	= $(AS_SRC:.s=.o)
PROJECT = hello_world


$(PROJECT).bin: $(PROJECT).elf
	$(CC)objcopy.exe -O binary $< $@

$(PROJECT).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AS_OBJ) -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin