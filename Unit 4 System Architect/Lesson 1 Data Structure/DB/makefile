
# makefile
# Created on: 15 Nov 2023
# Author: Shehab Elkhaligy
# Description: This file automate the building process of C language inorder to run on x86 Intel processors


# $< means dependency
# $@ means target
# % is generic type
# $(wildcard *(file_extension)) is used to gather all the files with specific extension in a variable
# $((VAR):(file_extension_1)=(file_extension_2)) is used to convert something like uart.c to uart.o

#Constants
CC		= 
INCS	= -I inc
SRC 	= $(wildcard $(SRC_DIR)/*.c)
OBJ 	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
# --- --- ---

CPU		= 
CFLAGS	= -Wall
LIBS	=
SRC_DIR = src
OBJ_DIR = rel
REL_DIR = rel
AS_SRC	= $(wildcard *.s)
AS_OBJ	= $(addprefix $(REL_DIR)/,$(AS_SRC:.s=.o))
PROJECT = Student_Database

# This will compile assemble and link in one shot, also it will pass standard libraries object files to the linker 
One_Shot:
	$(CC)gcc.exe $(CFLAGS) $(SRC) -I inc -o $(REL_DIR)/$(PROJECT).exe
default: $(REL_DIR)/$(PROJECT).exe
all: clean_all $(REL_DIR)/$(PROJECT).exe

$(REL_DIR)/$(PROJECT).exe: $(REL_DIR)/$(PROJECT).elf
	@echo Generating binary from $@
	$(CC)objcopy.exe -O binary $< $@
	@echo Generated binary: $<

$(REL_DIR)/$(PROJECT).elf: $(OBJ) 
	@echo Linking: $@
	$(CC)ld.exe $(LIBS) $(OBJ) -o $@ -Map=mapfile.map
	@echo Linked: $<
		

# $(info var is $(AS_SRC) $(AS_OBJ))
# release/startup.o: $(AS_SRC)
# 	@echo Assembling: $<
# 	arm-none-eabi-as.exe $(CFLAGS) $< -o $@
# 	@echo Assembled: $@

$(REL_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling and Assembling: $<
	$(CC)gcc.exe -Wall $(CFLAGS) -c $(INCS) $< -o $@
	@echo Compiled and Assembled: $@

# -f flag will make rm command not produce an error when there's no files
clean_all:
	rm -f release/*.o release/*.elf release/*.bin

clean:
	rm -f release/*.o release/*.elf release/*.exe







