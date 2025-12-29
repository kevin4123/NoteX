## IC Model

1. 

2. **IC-Model-2**
    - 模型方程 ( *Discrete System* )
        - 系统
            \[
            \left\{
            \begin{aligned}
            系统 &= \{\text{记忆}, \text{线网}\} \\
            线网 &= \{I, \text{Internals}, O\} \\
            I &= \{I_{\text{记忆}}, I_{\text{线网}}\}
            \end{aligned}
            \right.
            \]
        - 记忆(时序)
            \[
            \left\{
            \begin{aligned}
            S = \{所有记忆\} \\
            S_{next} = next(S,I)
            \end{aligned}
            \right.
            \]
        - 线网(组合)
            \[
            \left\{
            \begin{aligned}
            O = out(S,I) \\
            线网_1 = f_1() \\
            线网_2 = f_2() \\
            ...
            \end{aligned}
            \right.
            \]
        - 离散输入驱动模型 ( *Discrete Input Driver Model* )
            - ==当 $\{I_{记忆}, I_{线网}\}$ 不变化，$\{记忆, 线网\}$ 静止不变==
            $$I\ \text{changes} \;\Rightarrow\; 系统\ \text{changes}$$

    - 状态机
        - $$FSM = 
                \begin{Bmatrix}
                S \\
                S_{next} \\
                O
                \end{Bmatrix}
          $$
        