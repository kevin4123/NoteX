## LinkScript

```ld
MEMORY {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
    .isr_vector : {
        KEEP(*(.isr_vector))        /* 保留中断向量表 */
    } > FLASH

    .text : {
        *(.text*)
    } > FLASH

    .data : {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM AT > FLASH              /* 数据储存在 FLASH, 运行时复制到 RAM */

    .bss : {
        _sbss = .;
        *(.bss*)
        _ebss = .;
    } > RAM
}

```

1. 关键词
    - KEEP()        保留未引用节区:使用 KEEP 防止链接器优化掉未使用的节区(如中断向量表)
    - NOLOAD()      空节区处理:使用 NOLOAD 标记不加载到内存的节区(如调试信息)
    - 