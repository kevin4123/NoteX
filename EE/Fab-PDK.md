# PDK

*** 
Fab 提供
Wiki -> Process design kit
*** 

## ICsprout55

### Glossary of Terms

1. **ics55_LLSC_H7C_V1p10C100**        *naming convention*  
```yaml
LVT                     ->  低阈值电压(Low Vt)
HVT                     ->  (高 Vt，省电慢)
SVT                     ->  (平衡)
ics55                   ->  ICsprout55
LLSC                    ->  Low Leakage Standard Cell
H7                      ->  表示标准单元的高度为7个轨道
C                       ->  表示大版本号
V1p10C100               ->  表示具体的小版本
```

2. **标准单元的命名:功能+驱动能力+H+轨道数+阈值电压**

<pre>
NAND2X1H7L
- 二输入的与非门
- 驱动能力为X1, 即1倍标准驱动能力
- 其高度(H)为7个轨道
- 阈值电压为LVT
</pre>

<pre>
OR3X0P5H7R
- 三输入的或门
- 驱动能力为X0P5, 即0.5倍标准驱动能力(P表示小数点)
- 其高度(H)为7个轨道
- 阈值电压为RVT
</pre>

3. **PDK files**
```yaml
- .lib                    ->  标准单元模型(逻辑功能和PPA等)
- .v                      ->  行为模型
- ics55_LLSC_H7CL/.lef    ->  物理模型
- prtech/techLEF/.lef     ->  工艺规范
- .cdl                    ->  晶体管信息
```

- .cdl: 晶体管信息
```yaml
.SUBCKT 子电路名称 端口1 端口2 ...
晶体管实例名称 漏极 栅极 源极 衬底 晶体管类型 沟道宽度 沟道长度
...
.ENDS
```
>用于进行晶体管层次的SPICE仿真, 以及检查GDS版图与网表逻辑的一致性, 后者称为LVS(Layout Versus Schematic)

4. **PVT角(PVT corner)**
    1. 作用:
    - 用于描述不同工艺、不同温度、不同电压下的IC的特性
    - 保证芯片在大批量生产和各种工作环境下都能可靠工作的基石
    2. 三要素
    - 工艺角(process corner)
        - 工作速度分3种情况: t(typical), f(fast)和s(slow)
        - 组合出5种工艺角: ss, tt, ff, sf和fs
        - ss, tt和ff: nMOS和pMOS的工作速度基本保持一致
        >只影响晶体管的延迟, 不影响晶体管整体的功能

    - 电压(Voltage)
    - 温度(Temperature)
    3. 不同的PVT角体现为不同的LIB文件
    - 在这些LIB文件中, 标准单元的名称和面积都相同, 但延迟和功耗不同
    - 通过采用不同的LIB文件进行评估, 后端工程师可以了解芯片能否在对应PVT角下按预期工作
