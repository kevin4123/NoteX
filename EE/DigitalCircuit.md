## Digital Circuit

1. **Digital Circuit 1**
    - ***模型方程 ( *Discrete System* )***
        - 定义
            $$
            \begin{cases}
            System &= \{\text{Memory}, \text{Signals}\} \\
            Signals &= \{Trigger, I, Internals, O\} \\
            Trigger &= \{I_{clk}, I_{rst}\} \\
            \end{cases}
            $$
            - $I_{rst}$ 移出 $Trigger$ 改善时序
        - 特征
            $$
            \begin{cases}
            Memory_{next} &= next(System) \\
            Signals &= F(System) \\
            \end{cases}
            $$
        - 离散输入驱动模型 ( *Discrete Input Driver Model* )
            $$\{Trigger, I\}\ \text{运动} \;\Rightarrow\; \{System\}\ \text{运动}$$
    - ***亚稳态来源***
        - 基础: 
            - 亚稳态来源 **=** <font color="FF0000">async</font>
        - 解决方案:
            - <font color="FF0000">async</font> $\xRightarrow{\text{convert to }}\;$ <font color="008000 ">sync</font>
    - ***如何实现 <font color="008000 ">sync</font> ?***
        - 时钟域下 **收敛**
        - 满足: INPUT + 墙
        - 满足: $$ f_{clk} < f_{max} = \frac{1}{T_{Critical Path}} $$
    - ***Memory***
        - 作用: 
            - 记忆
            - 墙
                - 断流(阻止数据流向下流动)
                - 周期延迟
                - 异步转同步

2. **Digital Circuit 2**
    - ***Communication***
        - Latency
        - Interface
            - Data
            - Control
            - Handshake
            - ...
        - Protocol


## 设计流程
- $$设计_1 \xRightarrow{\text{验证 }}\; 设计_2 \xRightarrow{\text{验证 }}\; 设计_3 \xRightarrow{\text{验证 }}\; 设计_4$$
- 注意**Interface Communication** 的 相关的 attribute, 约定
- 编写 Signal 的 f(a,b,c)