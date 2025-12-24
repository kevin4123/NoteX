## RISCV

### Documents

[riscv-unified-db](https://riscv-software-src.github.io/riscv-unified-db/)
[RISC-V Non-ISA Specifications](https://github.com/riscv-non-isa)

### ToolChain
1. Source
    - [source link](https://github.com/riscv/riscv-gnu-toolchain)
    - [release link](https://github.com/riscv/riscv-gnu-toolchain/releases)
        - RISCstar Toolchain(官方生态)
        - xPack GNU RISC-V Embedded GCC(社区维护)

2. Components
    - Cross Compiler
    - Debugger
    - Linker
    - Libraries
        - glibc
        - newlib
        - uClibc
        - musl
    - Simulators(验证程序是否能在目标平台运行)
        - QEMU
        - Spike
        - Renode
        - Bochs

3. 适用平台
    - riscv64-elf-* : 裸机,newlib
    - riscv64-glibc-* : Linux，glibc

4. 使用方法

    1. riscv32-unknown-elf-gcc -march=rv32i -mabi=ilp32 -nostartfiles -g -O0 -WI,--entry=_start -WI,--Ttext=0x00400000 -WI,--Tdata=0x10010000 -o x.elf start.s main.c 
        - march=rv32i : ISA
        - mabi=ilp32 : ABI(int,long,pointer都是32位，参数通过寄存器a0-a7传递，返回值通过a0-a1传递)
        - nostartfiles : 自写 start.s
            - 默认 gcc 会自动链接：crt0.o;_start
            - 初始化 .data / .bss,调 main() 等

        - -Wl, 传参 给 Linker
        - --entry=_start : 指定入口函数
        - --Ttext=0x00400000 : 指定 .text 起始地址
        - --Tdata=0x10010000 : 指定 .data 起始地址

    2. riscv32-unknown-elf-objdump -d -S x.elf
        - -d : 打印汇编代码
        - -S : 打印C语言源码
    3. riscv32-unknown-elf-readelf -a x.elf
    4. riscv32-unknown-elf-objcopy -O ihex build/x.elf build/x.hex
        - -O ihex : 转换成 ihex 格式
    5. riscv32-unknown-elf-objcopy -O binary build/x.elf build/x.bin
        - -O binary : 转换成 binary 格式
    6. riscv32-unknown-elf-nm x.elf 
        - 打印符号表
    7. riscv32-unknown-elf-size x.elf
        - 打印内存占用






5. 