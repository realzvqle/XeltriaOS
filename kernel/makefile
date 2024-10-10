SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S) 
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(SRC_DIR)/%.S, $(OBJ_DIR)/%.o, $(ASM_FILES))

CC = aarch64-none-elf-gcc
AS = aarch64-none-elf-as
CFLAGS = -ffreestanding
ASFLAGS = 

all: $(OBJ_FILES) link

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.S
	@mkdir -p $(OBJ_DIR)
	$(AS) $(ASFLAGS) $< -o $@

link:
	aarch64-none-elf-ld -nostdlib -Tlinker.ld boot.o $(OBJ_FILES) -o kernel.elf

clean:
	rm -rf $(OBJ_DIR)
	rm -f boot.o kernel.elf
