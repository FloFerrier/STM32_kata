# README
## Build on cross-compilation
```bash
mkdir build
arm-none-eabi-gcc -c main.c -o build/main.o -mcpu=cortex-m4 -Og -g -gdwarf-2 -mthumb
arm-none-eabi-gcc -T stm32f446re.ld -nostdlib build/*.o -o build/firmware.elf
```

## Flash
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```
```bash
arm-none-eabi-gdb --tui
(gdb) target extended-remote localhost:3333
(gdb) monitor reset init
(gdb) monitor flash write_image erase build/firmware.elf
(gdb) monitor resume
```

## Debug
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```
```bash
arm-none-eabi-gdb --tui
(gdb) file build/firmware.elf
(gdb) target extended-remote localhost:3333
(gdb) monitor reset halt
(gdb) load build/firmware.elf
```