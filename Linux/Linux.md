## Linux

```bash     发行版+内核
https://www.linux.org/          分发版    
https://www.kernel.org/         内核
```

```bash
cat /etc/os-release             # 查看发行版名称和版本
echo $SHELL                     # 查看 shell
sudo dmesg                      # print or control the kernel ring buffer: 显示全部内核日志
```

## NetWork
```bash
ipconfig             			view host
ip addr
curl ifconfig.me                public IP
```

### VMware 配置
```bash			第一步
选择:
VMnet0（桥接）
VMnet1（Host-only）
VMnet8（NAT）

NAT为例:

Edit -> Virtual Network Editer		# 等价于路由器
VMware相当于一个路由器，在内部开了一个子网，给所有虚拟机分配ip地址

示例：
VMnet8 虚拟网络
子网IP:10.0.0.0
子网掩码：255.255.255.0
网关：               10.0.0.2（VMware NAT）
```

```bash			第二步	图形化网络管理工具	NetworkManager
Ubuntu:右上角图标，进去打开网络
```

```bash			改用命令行网络管理工具	networkd
配置文件：/etc/netplan/01-network-manager-all.yaml
修改为:
'network:
  version: 2
  renderer: networkd
  ethernets:
    ens33:
      dhcp4: true'
关闭networkManager
sudo systemctl stop NetworkManager
启用配置文件的配置
netplan apply 
查看networkd状态
sudo systemctl status systemd-networkd
关闭开机自启动
sudo systemctl disable NetworkManager
重启
reboot
```

```bash			networkctl
networkctl 				显示所有网络接口状态
networkctl status 		详细信息

```
```bash			使用静态IP
Static-IP: 由网络管理员手动分配的固定IP地址，不会随时间或设备重启而改变
Dynamic-IP: DHCP 服务器自动分配

修改配置文件:
'network:
  version: 2
  renderer: networkd
  ethernets:
    ens33:
      dhcp4: no
      addresses:[10.0.0.99/24]
      gateway4: 10.0.0.2
      nameservers:
        addresses: [8.8.8.8, 8.8.4.4]'

启用配置文件的配置
netplan apply 
```

### vm-tools
```bash			
官方说明：https://techdocs.broadcom.com/cn/zh-cn/vmware-cis/vsphere/tools/11-0-0/vmware-tools-administration-11-0-0/introduction-to-vmware-tools/open-vm-tools.html


建议去官网看最新的安装:
sudo apt-get update
sudo apt-get install open-vm-tools-desktop
sudo apt-get install open-vm-tools
```

### 远程连接					以主机 连接 虚拟机为例
```bash			
1 ping 虚拟机，确保网络通畅
2 windows 上设置 XShell 目标机器
3 ubuntu  上安装 openssh-server
sudo apt install openssh-server
查看状态
sudo systemctl status ssh
列出所有TCP+UDP的监听端口，用数字显示，并告诉我是谁在监听,就是查看四元组
sudo ss -tunlp
4 XShell 连接 ubuntu
```

## 用户管理
```bash
1 进入管理员权限
sudo -i
2 
添加新用户
useradd <username>
修改当前用户密码
passwd
修改他人密码,root权限
passwd <username>
3 用户切换
su - <username>
```

## 查看系统信息
```bash
uname -a
```

## 目录                   一切皆文件
```bash
1 配置文件

/etc/passwd             用户账户信息
格式：用户名:密码占位符:UID:GID:用户描述:家目录:登录 Shell

/etc/group              用户组信息

/etc/hosts              主机名和IP地址的映射关系
就是本地DNS

/etc/apt                APT 软件包管理器的配置

2 变量数据

/var/log                储存系统日志文件
/var/www                默认的Web服务器根目录
/var/lib                存储各种应用程序的数据文件

3 包含用户可共享的只读数据

/usr/bin                存储可执行文件            
/usr/sbin               储存系统管理员可执行文件
/usr/lib                储存共享库文件
/usr/share              储存共享数据和文档

4 个人用户
/home/<username>

5 启动过程中使用的文件
/boot

6 虚拟文件系统              提供有关正在运行的进程和系统内核的信息 

/proc/cpuinfo               CPU信息
/proc/meminfo               内存信息

相关命令
CPU  → lscpu   → 计算资源
RAM  → lsmem   → 地址空间

7 设备目录 挂载 mount

/dev
硬盘 = 文件
键盘 = 文件
鼠标 = 文件
终端 = 文件
随机数发生器 = 文件

字符设备 c              按字节/字符流处理,没有“寻址”            典型：键盘、终端、串口
/dev/tty
/dev/null
/dev/zero
/dev/random

块设备 b                按块（block）读写                      典型：硬盘、U盘、SSD
/dev/sda
/dev/sda1
/dev/nvme0n1

相关命令
DISK → lsblk   → 持久存储
```

### 文件识别
```bash
file <filename>                 识别文件类型等信息

依据：
Linux 不依赖后缀识别文件，依赖文件内容
判断依据： Magic number / Magic pattern

新建一个文件，任何后缀它的类型都是empty

当文件开头是 #!/bin/bash -> shell script
```


## 资源管理器
```bash
top                     相当于windows的任务管理器
```

## 挂载 mount
```bash
                    windows                                             Linux
             +--------------------------+                        +--------------------------+
             |                          |                        |                          |
             |  256G 固 态 硬 盘            |                        |  256G 固 态 硬 盘            |
             |                          |                        |                          |
             |                          |                        |                          |
             |  1 分 区                   |                        |  1 分 区                   |
             |  2 格 式 化 文 件 系 统 exfat   |                        |  2 格 式 化 文 件 系 统 ext4    |
             |                          |                        |                          |
             |          +------------+  |                        |                          |
             |          |            |  |                        |  +-------------------+   |
  c 盘   +----------->   |   区 1      |  |                        |  |                   | <------------+
             |          |            |  |                        |  |  /dev/sda1        |   |             /mnt/fileA
             |          |            |  |                        |  |                   | +------------>
             |          +------------+  |                        |  |                   |   | mount
             |                          |                        |  +-------------------+   |
             |                          |                        |                          |
             |                          |                        |                          |
             |          +------------+  |                        |  +-------------------+   |
             |          |            |  |                        |  |                   |   |
  d 盘   +----------->   |   区 2      |  |                        |  |  /dev/sda2        | <------------+
             |          |            |  |                        |  |                   |   |             /mnt/fileB
             |          |            |  |                        |  |                   | +------------>
             |          +------------+  |                        |  +-------------------+   | mount
             |                          |                        |                          |
             |                          |                        |                          |
             +--------------------------+                        +--------------------------+

lab:

虚拟机的 /dev/sr0 -> 此时为CD光驱的设备文件

新建一个文件夹
mkdir /home/kevin/Desktop/cd-dir/
挂载
mount /dev/sr0 /home/kevin/Desktop/cd-dir/

目录下可以看见文件架构了

取消挂载
umount /home/kevin/Desktop/cd-dir/
```
