@echo off

qemu-system-aarch64 -M 6GB -machine virt -cpu cortex-a57 -kernel kernel/kernel.exe -device ramfb  -device virtio-keyboard -display sdl -serial mon:stdio 
