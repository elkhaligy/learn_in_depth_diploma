#Author: Shehab Elkhaligy
# $< means dependency
# $@ means target
# % is generic type
# $(wildcard *(file_extension)) is used to gather all the files with specific extension in a variable
# $((VAR):(file_extension_1)=(file_extension_2)) is used to convert something like uart.c to uart.o

#Constants
CC		= arm-none-eabi-
INCS	= -I inc
SRC 	= $(wildcard $(SRC_DIR)/*.c)
OBJ 	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
# --- --- ---


CPU		= arm926ej-s
CFLAGS	= -g -mcpu=$(CPU)
LIBS	=
SRC_DIR = src
OBJ_DIR = release
REL_DIR = release
AS_SRC	= $(wildcard *.s)
AS_OBJ	= $(addprefix $(REL_DIR)/,$(AS_SRC:.s=.o))
PROJECT = hello_world

$(info var is $(AS_SRC) $(AS_OBJ))
$(REL_DIR)/$(PROJECT).bin: $(REL_DIR)/$(PROJECT).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo $@ done

$(REL_DIR)/$(PROJECT).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) release/startup.o -o $@
	@echo $@ done

release/startup.o: $(AS_SRC)
	arm-none-eabi-as.exe $(CFLAGS) $< -o $@
	@echo $@ done

$(REL_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@
	@echo $@ done

clean_all:
	rm release/*.o release/*.elf release/*.bin

clean:
	rm release/*.elf release/*.bin






