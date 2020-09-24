binaries: cleanup
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"./main.d" -MT"./main.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./startup.o" "./startup.S"
registers:
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c  --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./registers.o" "./registers.c"
main:
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c  --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./main.o" "./main.c"
link: binaries registers main
	arm-none-eabi-ld -T linker -S -o program.elf main.o startup.o registers.o
build: link
	arm-none-eabi-objcopy -O binary program.elf program.bin
log1:
	arm-none-eabi-objdump -d program.elf > dis
log2:
	arm-none-eabi-objdump -d -s program.elf > dis2
cleanup:
	git clean -fdx
all: binaries registers main link build log1 log2