## QEMU

1. 简介
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
- 使用
```bash
qemu-system-riscv32 -machine virt -bios none -nographic -serial mon:stdio	# 开发板，串口->终端
# 调试控制台 
(qemu) Ctrl-A	+ C					# 启动控制台
(qemu) info registers				# 查看寄存器
(qemu) q							# 退出
(qemu) info mtree					# 查看内存映射信息
```