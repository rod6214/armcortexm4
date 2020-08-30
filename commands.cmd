# Compile
arm-none-eabi-as -mapcs-32 -mcpu=cortex-m4 -march=armv7 -o program.o main.S
# Link
arm-none-eabi-ld -T linker -o program.elf program.o
arm-none-eabi-ld -Ttext=0x80001ac -TVectorTable=0x8000000 -o program.elf program.o
arm-none-eabi-ld -Tdata=0x20000000 -Ttext=0x80001ac -o program.elf program.o
# Create binary
arm-none-eabi-objcopy -O binary program.elf program.bin
# Create hex
arm-none-eabi-objcopy -O ihex program.elf program.hex
# Dissasembly
arm-none-eabi-objdump -d program.elf > dis
# Disassemble binaries
arm-none-eabi-objdump -d -s program.elf > dis2
arm-none-eabi-objdump -D -bbinary -marm program.bin -Mforce-thumb > <output.s>
arm-none-eabi-objdump -D -bbinary -marm program.bin -Mforce-thumb > <output.s>
arm-none-eabi-objdump -b binary -m arm -D program.bin -Mforce-thumb --adjust-vma=0x08000000 > dis2.s