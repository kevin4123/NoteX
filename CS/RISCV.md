## RISCV

### riscv-unified-db

[riscv-unified-db](https://riscv-software-src.github.io/riscv-unified-db/)

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

- riscv32-unknown-elf-gcc -nostartfiles -nostdlib start.s -o start.elf


5. 