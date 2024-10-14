all:
	cd loader && make
	cp boot.o kernel/boot.o
	rm boot.o
	cd kernel && make
	
	

clean:
	cd kernel && make clean



run:
	make all
	qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel kernel/kernel.elf -device ramfb  -device virtio-keyboard -display sdl -serial mon:stdio 


run-moniter:
	make all
	qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel kernel/kernel.elf -device ramfb -device virtio-keyboard -display sdl -monitor stdio 