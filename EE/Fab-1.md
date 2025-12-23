## Transistor
1. Category
    - BJT
    - FET
        - JFET(Junction FET)
        - MOSFET(Metal-Oxide-Semiconductor FET)
            - Enhancement
            - Depletion
        - Special FETs
            - HEMT(High Electron Mobility)
            - MESFET(Microwave FET)
            - FinFET(Advanced IC)           (营销术语:5nm)
            - GAAFET(Advanced IC)(20-30nm)  (营销术语:3nm)
            - TFET(Tunnel FET)




## Standard cell

<u>以icsprout55为例</u>

1. Category
    1. 逻辑门单元
        - 基本逻辑门
        - 复杂逻辑门:OAI22X1H7L
    2. 时序单元
        - DFFX1H7L
    3. I/O单元
        - 数据I/O单元(GPIO):P65_1233_PBMUX
        - 核心电源单元:P65_1233_VDD1;P65_1233_VSS1
        - I/O电源单元:P65_1233_VSSIO3;P65_1233_VDDIO3
    4. 驱动单元
        - 逻辑正向驱动单元,又称缓冲器(buffer):BUFX1H7L;BUFX2H7L;BUFX4H7L
        - 逻辑反向驱动单元,又称反相器(inverter)
    5. 物理单元
        - 上拉/下拉单元:TIELOH7L;TIEHIH7L
        - 填充单元(filler):FILLER1H7L;FILLER2H7L
        - 去耦单元(decap):FILLCAP4H7L;FILLCAP8H7L
        - 天线效应修复单元:ANT2H7L;ANT4H7L
    6. 宏单元
        - SRAM存储器
        - DDR phy模块
    7. 复杂功能单元
        - 多路选择器
        - 全加器
        - 比较器
        - MUX2X1H7L;MUXI2X1H7L;ADDHX1H7L;ADDFX1H7L
    8. 时钟专用单元
        - 时钟缓冲器
        - 时钟门控(clock gating)单元
        - 用于处理时钟信号的逻辑门单元
        - ICGX1H7L;ICGNX1H7L
    9. 电源管理单元
        - 电源门控(power gating)单元
        - 隔离单元
    10. 测试调试单元
        - 扫描链(scan chain)单元
        - 内建自测试(Built-In Self Test, BIST)控制单元
        - SDFFX1H7L;SDFFSX1H7L;SDFFRX1H7L
