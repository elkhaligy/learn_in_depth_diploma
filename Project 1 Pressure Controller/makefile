#
# 	main.c
#
#  Created on: Nov 27, 2023
#  Author: Shehab Elkhaligy
#  Descritpion: Inorder for this makefile to work, make sure you have the toolchain path exported
# 				Also for flashing to work, make sure 
#

#Author: Shehab Elkhaligy
# $< means dependency
# $@ means target
# % is generic type
# $(wildcard *(file_extension)) is used to gather all the files with specific extension in a variable
# $((VAR):(file_extension_1)=(file_extension_2)) is used to convert something like uart.c to uart.o

#Constants
CC		= arm-none-eabi-
INCS	= -I src
SRC 	= $(wildcard $(SRC_DIR)/*.c)
OBJ 	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
# --- --- ---


CPU		= cortex-m3
#CFLAGS	= -g -gdwarf-2 -Wall -mcpu=$(CPU) #Debug
CFLAGS	= -Wall -mcpu=$(CPU) #Release
LIBS	=
LINKER 	= $(wildcard *.ld)
SRC_DIR = src
OBJ_DIR = obj
REL_DIR = rel
AS_SRC	= $(wildcard *.s)
AS_OBJ	= $(addprefix $(REL_DIR)/,$(AS_SRC:.s=.o))
PROJECT = Pressure_Controller

.PHONY: default all map flash erase axf
# default and all are targets with dependnecies while map is a target without a depencency
default: 	$(REL_DIR)/$(PROJECT).bin
all: 		clean_all $(REL_DIR)/$(PROJECT).bin
windows:
	gcc.exe -Wall $(SRC) $(INCS) -o $(REL_DIR)/$(PROJECT).exe
map: 		
	$(CC)ld.exe -T $(LINKER) $(LIBS) $(OBJ) -o $@ -Map=mapfile.map
	@echo Successful Operation!
flash: erase
	st-flash.exe erase
	st-flash.exe write $(REL_DIR)/$(PROJECT).bin 0x8000000
	echo Succsseful Operation!
erase:
	st-flash.exe erase
	echo Succsseful Operation!
axf:
	cp $(REL_DIR)/$(PROJECT).elf $(REL_DIR)/$(PROJECT).axf

# $(info var is $(AS_SRC) $(AS_OBJ))
$(REL_DIR)/$(PROJECT).bin: $(REL_DIR)/$(PROJECT).elf
	@echo Generating Binary From {$<} Into {$@}
	$(CC)objcopy.exe -O binary $< $@
	@echo Successful Operation!
	@echo ================================================================

$(REL_DIR)/$(PROJECT).elf: $(OBJ) 
	@echo Linking {$(OBJ)} Into {$@}
	$(CC)ld.exe -T $(LINKER) $(LIBS) $(OBJ) -o $@
	@echo Successful Operation!
	@echo ================================================================

# release/startup.o: $(AS_SRC)
# 	@echo Assembling: $<
# 	arm-none-eabi-as.exe $(CFLAGS_DEBUG) $< -o $@
# 	@echo Assembled: $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling and Assembling {$<} Into {$@}
	$(CC)gcc.exe $(CFLAGS_DEBUG) -c $(INCS) $< -o $@
	@echo Successful Operation!
	@echo ================================================================
# -f flag will make rm command not produce an error when there's no files
.PHONY: clean # This is used incase a file with the name clean is in the directory 
clean:
	rm -f $(OBJ_DIR)/*.o $(REL_DIR)/*.elf $(REL_DIR)/*.exe $(REL_DIR)/*.bin *.map
	@echo Successful Operation!
# only clean executables
.PHONY: clean_ex
clean_ex:
	rm -f $(REL_DIR)/*.elf $(REL_DIR)/*.bin
	@echo Successful Operation!








