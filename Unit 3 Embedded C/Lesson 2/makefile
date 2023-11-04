#Author: Shehab Elkhaligy
# $< means dependency
# $@ means target

CPU		= arm926ej-s
CC		= arm-none-eabi-
CFLAGS	= -g -mcpu=$(CPU)
INCS	= -I .
LIBS	= 

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@

learn-in-depth.elf: startup.o main.o uart.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o main.o uart.o -o $@

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

main.o: main.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

uart.o: uart.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin