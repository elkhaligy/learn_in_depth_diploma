#Author: Shehab Elkhaligy


CPU		= arm926ej-s
CC		= arm-none-eabi-
CFLAGS	= -g -mcpu=$(CPU)
INCS	= -I .
LIBS	= 

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin

learn-in-depth.elf: startup.o main.o uart.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o main.o uart.o -o learn-in-depth.elf 

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) startup.s -o startup.o

main.o: main.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) main.c -o main.o

uart.o: uart.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) uart.c -o uart.o

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin