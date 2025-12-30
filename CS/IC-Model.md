## IC Model

1. 

2. **IC-Model-2**
    - ***模型方程 ( *Discrete System* )***
        - 系统
            \[
            \left\{
            \begin{aligned}
            系统 &= \{\text{记忆}, \text{线网}\} \\
            线网 &= \{I, \text{Internals}, O\} \\
            I &= \{I_{\text{记忆}}, I_{\text{线网}}\} \\
            I_{记忆} &= \{I_{clk}, I_{not-clk}\}
            \end{aligned}
            \right.
            \]
        - 记忆(时序)
            \[
            \left\{
            \begin{aligned}
            S &= \{所有记忆\} \\
            S_{next} &= next(S,I) \\
            S_{next} &= next(S): 封闭系统时
            \end{aligned}
            \right.
            \]
        - 线网(组合)
            \[
            \left\{
            \begin{aligned}
            O &= out(S,I) \\
            线网_1 &= f_1() \\
            线网_2 &= f_2() \\
            ...
            \end{aligned}
            \right.
            \]
        - 离散输入驱动模型 ( *Discrete Input Driver Model* )
            - ==当 $\{I_{记忆}, I_{线网}\}$ 不变化，$\{记忆, 线网\}$ 静止不变==
            $$I\ \text{changes} \;\Rightarrow\; 系统\ \text{changes}$$

    - ***状态机***
        - $$FSM = 
                \begin{Bmatrix}
                S \\
                S_{next} \\
                O
                \end{Bmatrix}
          $$
 
    - ***亚稳态来源***
        - 为什么会有亚稳态呢？
            - 基础: 
                - $I_{记忆} = \{I_{clk}, I_{not-clk}\}$
                - {记忆} 周围的所有输入信号 (除 $I_{clk}$ 以外) = $\{I_{not-clk}, I_{线网}\}$: 都是**异步输入**(亚稳态来源)
            - 结论: 
                - 亚稳态来源 = $\{I_{not-clk}, I_{线网}\}$
            - 解决方案:
                - 把 {记忆} 周围的 {亚稳态来源} 全部转为**同步输入**
    - ***何为同步输入 ?***
        - 本质上
            - {记忆} 周围的所有输入信号 (除 $I_{clk}$ 以外) 都是 **异步输入**
            - **开放系统(详情看excalidraw)** 不存在 **同步输入**
        - 如何实现 **同步输入** ?
            - **封闭系统(详情看excalidraw)** **(收敛的)** 内部都是 **同步输入** 

    - ***记忆***
        - 作用: 
            - 记忆
            - 断流(阻止数据流向下流动)
            - 创造周期延迟

3. **IC-Model-3**
        