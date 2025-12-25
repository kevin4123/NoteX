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

5. 链接脚本 
    - 内存布局:定义不同内存区域(如 ROM、RAM)的地址范围和属性
    - 段(节区, section)分配:指定输入目标文件的节区如何合并到输出文件的节区，并分配到特定内存区域
    - 符号处理:设置入口点、定义符号地址、处理未引用节区等

```ld
OUTPUT_ARCH(riscv)

ENTRY(_start)           /* 入口 */

SECTIONS {
    
    . = 0x00400000;     /* .text 起始地址 */

    .text : {
        *(.text)
        *(.text.*)
    }

    . = 0x10010000;     /* .data 起始地址 */

    .data : {
        *(.data)
        *(.data.*)
        *(.rodata)
        *(.rodata.*)    
    }

    .bss : {
        _bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
    }
}
```
6. ELF
    1. readelf: 查看 ELF 结构
        - riscv32-unknown-elf-readelf -a firmware.elf   # 查看所有段的名称、符号名和地址
        - riscv32-unknown-elf-readelf -l firmware.elf   # 查看程序头部表
        - riscv32-unknown-elf-readelf -S firmware.elf   # 查看节区头部表
    2. objdump: 反汇编
        - riscv32-unknown-elf-objdump -d firmware.elf   # 反汇编
        - riscv32-unknown-elf-objdump -h firmware.elf   # 输出各个段的详细参数
    3. objcopy: 制作flash固件
        - riscv32-unknown-elf-objcopy -O binary firmware.elf firmware.bin   # 导出所有段的二进制文件
        - riscv32-unknown-elf-objcopy -dump-sections .text=text.bin firmware.elf    # 导出代码段的二进制文件