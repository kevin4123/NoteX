## RISC-V Open Source Supervisor Binary Interface (OpenSBI)

1. 简介
    - The **RISC-V Supervisor Binary Interface (SBI)** is the recommended interface between:
        - A platform-specific firmware running in M-mode and a bootloader, a hypervisor or a general-purpose OS executing in S-mode or HS-mode.
            ```
            [M模式固件] ←SBI→ [S模式软件]
                                ├─ 引导程序
                                ├─ 操作系统
                                └─ 虚拟机监控程序（HS模式）
            ```
        - A hypervisor running in HS-mode and a bootloader or a general-purpose OS executing in VS-mode.
            ```
            [HS模式虚拟机监控程序] ←SBI→ [VS模式软件]
                                            ├─ 引导程序
                                            └─ 操作系统
            ```
    - OpenSBI 的主要作用是:
        - 承上: 被上一级引导程序(如 U-Boot)加载，或者自己作为固件直接打包内核
        - 启下: 为运行在 S-mode 的操作系统提供统一的硬件抽象接口, 同时管理底层硬件的初始化与多核协作
        - 启动完成后,它持续驻留在后台,为运行在监管者模式的操作系统内核(如 Linux, FreeRTOS, Xv6 等)提供服务

