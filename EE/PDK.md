## PDK
Fab 提供
Wiki -> Process design kit

### ICsprout55

#### Glossary of Terms
```bash
ics55_LLSC_H7C_V1p10C100    # 命名

LVT                     ->  低阈值电压(Low Vt)
HVT                     ->  (高 Vt，省电慢)
SVT                     ->  (平衡)
ics55                   ->  ICsprout55
LLSC                    ->  Low Leakage Standard Cell
H7                      ->  表示标准单元的高度为7个轨道
C                       ->  表示大版本号
V1p10C100               ->  表示具体的小版本
```

```bash
PDK文件

.lib                    ->  标准单元的逻辑功能和PPA等信息
.v                      ->  标准单元的 verilog
ics55_LLSC_H7CL/.lef    ->  标准单元的物理几何信息
prtech/techLEF/.lef     ->  工艺规范
.cdl                    ->  晶体管信息
```

```bash
标准单元的命名:功能+驱动能力+H+轨道数+阈值电压

NAND2X1H7L              ->  二输入的与非门
                        ->  驱动能力为X1, 即1倍标准驱动能力
                        ->  其高度(H)为7个轨道
                        ->  阈值电压为LVT
OR3X0P5H7R              ->  三输入的或门
                        ->  驱动能力为X0P5, 即0.5倍标准驱动能力(P表示小数点)
                        ->  其高度(H)为7个轨道
                        ->  阈值电压为RVT
```