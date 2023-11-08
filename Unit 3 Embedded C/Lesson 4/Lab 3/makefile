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

CPU		= cortex-m4
CFLAGS	= -g -gdwarf-2 -mcpu=$(CPU)
LIBS	=
SRC_DIR = src
OBJ_DIR = release
REL_DIR = release
AS_SRC	= $(wildcard *.s)
AS_OBJ	= $(addprefix $(REL_DIR)/,$(AS_SRC:.s=.o))
PROJECT = TIVAC_Cortex_M4

default: $(REL_DIR)/$(PROJECT).bin
all: clean_all $(REL_DIR)/$(PROJECT).bin

$(REL_DIR)/$(PROJECT).bin: $(REL_DIR)/$(PROJECT).elf
	@echo Generating binary from $@
	$(CC)objcopy.exe -O binary $< $@
	@echo Generated binary: $<

$(REL_DIR)/$(PROJECT).elf: $(OBJ) 
	@echo Linking: $@
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=mapfile.map
	@echo Linked: $<
	@echo Creating .axf
	cp $(REL_DIR)/$(PROJECT).elf $(REL_DIR)/$(PROJECT).axf
	@echo Created $(REL_DIR)/$(PROJECT).axf from $(REL_DIR)/$(PROJECT).elf
		

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
	rm -f release/*.elf release/*.bin






