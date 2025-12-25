## ELF

1. a.out(Assembler Output)
    - 1970s
    - 最早的 Unix 目标文件格式
2. COFF(Compact Object File Format)
    - 1980s
    - AT&T System V 引入
    - Windows 早期使用
3. PE(Portable Executable)
    - 1993s
    - Windows 95 / NT 系列
    - COFF 的扩展
    - 结构
        - DOS 头 + PE 头 + Section Table + Data
        - 支持导入表 / 导出表Import/Export Table(Import/Export Table)
        - 支持资源(icons, strings)
        - 支持动态链接库(DLL)
4. ELF(Executable and Linkable Format)
    - 1990s
    - Unix 标准
    - Section / Segment 分离
    - 动态链接表支持(GOT, PLT, .dynamic)
