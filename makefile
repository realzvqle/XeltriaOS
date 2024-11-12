all:
	cd kernel && xmake build

run:
	make all
	qemu-system-aarch64 -M 6GB -machine virt -cpu cortex-a57 -kernel kernel/kernel.elf -device ramfb  -device virtio-keyboard -display sdl -serial mon:stdio 

configure:
	cd kernel && xmake f --toolchain=aarch64-toolchain
clean:
	cd kernel && make clean