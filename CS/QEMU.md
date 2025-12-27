## QEMU

1. 简介
    - [官网](https://www.qemu.org/)
    - 全系统模拟(Full System Emulation)
    - 用户模式模拟(User Mode Emulation)
    - 支持 x86,x86_64,ARM,AArch64,RISC-V,MIPS,PowerPC 等
    - 虚拟化支持: 在宿主机 CPU 与目标 CPU 架构相同的情况下，可以通过 KVM 提供接近原生的性能
    - 外设模拟: 提供丰富的设备模型，如网络接口、存储设备、GPU（部分支持）、USB 等
    - 调试与开发支持: 支持 GDB 调试接口，可用于 OS 或固件的开发调试

2. RISCV 支持
    - 处理器相关
        - RISC-V 指令集
        - 特权级架构: 机器模式(M-mode)、用户模式(U-mode)、超级用户模式(S-mode)
        - 扩展支持
            - 逐步支持 V扩展(向量指令),H扩展(虚拟化),Zicsr(控制状态寄存器) 等
        - 多核模拟: 如SMP系统
    - 开发板相关
        - 预定义开发板: 如 virt, sifive_u, microchip-polarfire
        - 外设模拟: UART,CLINT(核心本地中断器),PLIC(平台本地中断器),VirtIO设备(磁盘、网络、GPU),PCIe 总线
    - 启动方式
        - 直接加载RISC-V内核镜像(如Linux的Image文件)，设备树(DTB)
        - 通过Bootloader(如U-Boot)启动

3. 使用
- 安装 
```bash
sudo apt-get update
sudo apt-get install qemu-system-misc
```
- 验证
```bash
qemu-system-riscv32 -version
```
- Virt Platform
    - Cores: 多达512核, 可选扩展
    - CLINT: (Core Local Interruptor)核心本地中断控制器
    - PLINT：(Platform-Level Interrupt Controller)平台级本地中断控制器
    - CFI并行NOR闪存: 用于存储固件或配置数据
    - UART: 1 个 NS16550 兼容的 UART, 用于串行通信
    - RTC: 1 个 Google Goldfish RTC，用于实时时钟功能
    - VirtIO-MMIO 传输设备: 8个 VirtlO-MMIO 传输设备, 用于虚拟化环境中的设备通信
    - PCle 主桥: 1 个通用的 PCle 主桥, 用于连接 PCle 设备s
    - fw_cfg 设备: 允许 guest 从 QEMU 获取数据

- Usage
    1. program: qemu-system-riscv32
    2. options
        - -machine virt: 指定虚拟化平台
        - -bios none: 不加载 BIOS
        - -nographic: 不显示图形界面
        - -serial mon:stdio: 将控制台输出重定向到标准输出
        - -kernel <filename/kernel>: 指定运行程序/内核
        - -d item1[,...]: 启用调试选项

    3. Multiplexer Keys
        - (qemu) Ctrl+a c: Rotate between the frontends connected to the multiplexer (usually this switches between the monitor and the console)
        - (qemu) Ctrl+a x: Exit emulator
        - (qemu) Ctrl+a h: Print this help
    4. Monitor commands
        - (qemu) info registers: Show the cpu registers
        - (qemu) info mtree: Show memory tree
        - (qemu) q: Quit the emulator
        - (qemu) info tlb: Show TLB entries
        - 