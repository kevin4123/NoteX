## Digital

**原则:**
- Everything is a signal.
- Use memory only for state transition, and implement everything else as pure function computation.
- Refactor: Separate stateful transitions from pure business logic.

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
    - 离散事件模型 ( *Discrete Event Model* )
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

- ***Transitivity***
    - if **a** is <font color="FF0000">async</font>, then **f(a)** is <font color="FF0000">async</font> 
    - if **a** changes, then **f(a)** changes

- ***Communication***
    - Latency
    - Interface
        - Data{}
        - Control{}
        - Handshake{}
        - Status{}
        
        - Flow{}
        - Interrupt{}
        - Coherence{}
        - Configuration{}
        - Debug{}
        - Arbitration{}
        - Sideband{}
        - Power{}
