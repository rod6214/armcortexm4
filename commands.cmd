# Compile
arm-none-eabi-as -mapcs-32 -mcpu=cortex-m4 -march=armv7 -o program.o main.S
arm-none-eabi-as -mapcs-32 -mcpu=cortex-m4 -march=armv7 -o program.o main.S startup.S (latest)
# Link
arm-none-eabi-ld -T linker -o program.elf program.o
arm-none-eabi-ld -T linker -S -o program.elf program.o (latest)
arm-none-eabi-ld -T linker -o program.elf program.o main.o
arm-none-eabi-ld -T linker -S -o program.elf program.o main.o
arm-none-eabi-ld -Ttext=0x80001ac -TVectorTable=0x8000000 -o program.elf program.o
arm-none-eabi-ld -Tdata=0x20000000 -Ttext=0x80001ac -o program.elf program.o
# To read elf
arm-none-eabi-readelf -S program.elf
# Create binary
arm-none-eabi-objcopy -O binary program.elf program.bin (latest)
# Create hex
arm-none-eabi-objcopy -O ihex program.elf program.hex
# Dissasembly
arm-none-eabi-objdump -d program.elf > dis (latest)
# Disassemble binaries
arm-none-eabi-objdump -d -s program.elf > dis2 (latest)
arm-none-eabi-objdump -D -bbinary -marm program.bin -Mforce-thumb > <output.s>
arm-none-eabi-objdump -D -bbinary -marm program.bin -Mforce-thumb > <output.s>
arm-none-eabi-objdump -b binary -m arm -D program.bin -Mforce-thumb --adjust-vma=0x08000000 > dis2.s
# To compile C
arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"./main.d" -MT"./main.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./main.o" "./main.S"
arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"./main.d" -MT"./main.o" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./startup.o" "./startup.S"
arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c  --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "./main.o" "./main.c"