SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CC = aarch64-none-elf-gcc
CFLAGS = -ffreestanding

all: $(OBJ_FILES) link

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

link:
	aarch64-none-elf-ld -nostdlib -Tlinker.ld boot.o obj/*.o -o kernel.elf

clean:
	rm -rf $(OBJ_DIR)
	rm boot.o
	rm kernel.elf