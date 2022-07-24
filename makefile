
all: test.bin

pre:
	@if ! which arm-none-eabi-gcc ; then  \
		printf "Cross compiler not found\n"; \
		false; \
	fi 

test.o: pre test.c
	arm-none-eabi-gcc -c -mcpu=arm926ej-s -g test.c -o test.o

startup.o: startup.s
	arm-none-eabi-as -mcpu=arm926ej-s -g startup.s -o startup.o

test.elf: test.o startup.o test.ld
	arm-none-eabi-ld -T test.ld test.o startup.o -o test.elf

test.bin: test.elf
	arm-none-eabi-objcopy -O binary test.elf test.bin

run: test.bin
	@qemu-system-arm -M versatilepb \
		-m 128M \
		-nographic \
		-audiodev none,id=none \
		-global pl041.audiodev=none \
		-kernel test.bin

clean:
	rm -f test.elf test.bin test.o startup.o
