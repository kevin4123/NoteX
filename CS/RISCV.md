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
        - QEMU      **详情看 [QEMU.md](QEMU.md)**
        - Spike
            - RISC-V 官方提供,专注于 RISC-V 指令集的功能验证
            - 简单设备支持: Spike 只提供最基本的设备模型(如简单的 UART 输出),不支持复杂外设或完整系统仿真
        - Renode
            - 主要用于嵌入式系统和物联网设备开发
            - 多架构支持: ARM、RISC-V、PowerPC、x86 等
            - 全系统模拟: 支持 MCU、SoC、外围设备的完整仿真
            - 外设丰富: 提供 GPIO、UART、SPI、I2C、PWM、网络、传感器等多种设备模拟
        - Bochs
            - x86/x86_64 全系统模拟器
            - 全系统模拟: 完整 PC 系统，包括 BIOS、硬盘、显示、网络接口等
            - 高度可配置: 支持不同的 x86 CPU 型号、内存大小、硬盘类型等配置

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

7. 库(Library)
    1. 运行时库(runtime library)
        - 相关的编译选项
            - -nostartfiles : 不使用 crt0.o 和 _start

    2. C 标准库(C standard library)
        - 相关的编译选项
            - -ffreestanding : 不依赖标准库

        - newlib
            - 需要实现: _read、_write、_sbrk

    3. libgcc(底层支持库：如 整数除法、浮点运算等)
        - 相关的编译选项
            - -nostdlib : 不使用标准库(包括libgcc和运行库)
            - -nodefaultlibs : 不使用默认库(包括libgcc)
        - 异常处理和信号传递
            - 异常处理(Exception Handling)
                - 提供对硬件异常(如非法指令、除以零)的支持
                - try-catch 它生成了调用 libgcc 提供的栈展开（unwind）函数
                    - 遍历调用栈
                    - 找到匹配的 catch
                    - 调用析构函数
            - 信号传递
                - 支持信号传递机制,用于处理软件中断和用户空间的信号
        - 双精度和长整数的支持
            - 如果硬件不支持双精度和长整数，libgcc 会模拟它们

8. GCC/Clang
    1. 选项
        - -fno-builtin : 不使用内置函数 
            - GCC 为了提高效率和代码优化,提供了一些内置函数,编译器直接处理生成汇编，不调用libc库函数
            - -fno-builtin 告诉编译器,不要自动把标准库函数变成内联/汇编，严格按代码调用
    2. 关键字
    ```c
    // 结构体大小为 5 字节, 无填充
    struct __attribute__((__packed__)) Example {
        char a;
        int b;
    }
    ```

    3. 内联汇编(inline assembly)
    ```c
    /*
    * 1. 一句 C语言代码 = 一小段顺序执行的 汇编代码
    * 2. 特权指令 / CSR / 控制寄存器 / 屏障指令 等, C语言 中无法直接访问
    */
    // CSR指令
    #define READ_CSR(csr_no,val) \
        asm volatile ("csrr %0, " #csr_no : "=r"(val))      // # 表示拼接

    #define WRITE_CSR(csr_no,val) \
        asm volatile ("csrw " #csr_no ", %0" :: "r"(val))

    #define MEPC 0x341

    int val;

    READ_CSR(MEPC, val);
    WRITE_CSR(MEPC, 0x1234);

    // 屏障指令
    asm volatile ("fence iorw, iorw");
    ```

    - 内联汇编语法
    ```c
    asm [volatile] (
        "汇编指令模板"                  // %0 %1 %2 ... 是占位符
        : 输出操作数                    // "约束"(变量)
        : 输入操作数                    // "约束"(变量/表达式)
        : 破坏描述（clobber）           // 列出被修改的寄存器或内存
    );
    ```

    - 语法示例
    ```c
    int add(int a, int b) {
        int result;
        asm volatile (
            "add %0, %1, %2"           
            : "=r"(result)              // 输出到 result
            : "r"(a), "r"(b)            // 输入 a 和 b
        );
        retrun result;
    }
    ```

    4. 原子操作(atomic)
    ```c
    // 需要A扩展
    int atomic_swap(int *ptr,int new_val){
        int old_val;
        asm volatile (
            "amoswap.w.aq %0, %2, %1"   // 原子交换
            : "=r"(old_val), "+A" (ptr) // 输出到 old_val, 输入到 ptr
            : "r"(new_val)
            : "memory"  // 表示内存被修改
        )；
        return old_val;
    }

    ```

    9. 异常、中断和特权模式
        - 看 **详情看 [QEMU.md](QEMU.md)**

