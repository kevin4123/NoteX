## Logic Simulation

1. **离散事件仿真 （Discrete Event Simulation）**
    - 仿真机制: 离散事件仿真
    - 仿真原理 
        - 依据: [离散输入驱动模型](IC-Model.md)
            $$I\ \text{changes} \;\Rightarrow\; 系统\ \text{changes}$$
        - 推论
            $$I \; changes \xRightarrow{\text{rule 1}}\; signal_1 \; changes\;\xRightarrow{\text{rule 2}}\; signal_2 \; changes \;\xRightarrow{\text{rule 3}}\; signal_3 \; changes \;\xRightarrow{\text{rule 4}}\; signal_4 \ \text{changes}$$
        - 结论
            - signal 改变 $\xRightarrow{\text{视为}}\;$ 事件发生 <br><br>
            - 事件队列: $事件_1 \xRightarrow{\text{激活}}\; 事件_2 \xRightarrow{\text{激活}}\; 事件_3 \xRightarrow{\text{激活}}\; 事件_4$ <br><br>
            - 等到所有事件队列全部收敛完成, 模拟结束 <br><br>
            - 等待下一事件发生
2. 分类
    1. Event-based
        - 代表工具: ModelSim; VCS; iVerilog
        - 动态调度,求值顺序在仿真过程中(运行时刻)决定
        - 较慢，需要维护事件队列
        - 同步电路/异步电路/混合电路
        - 步进: timescale
        - 功能验证
        - 时序验证: 有逻辑时序, *但是没有真实的时序(无延迟信息)*

    2. Cycle-based
        - 代表工具: Verilator 
        - 静态调度,求值顺序在仿真开始前(编译时刻)决定
        - 较快, 编译时已经确定事件队列
        - 同步电路( 无时间戳, 不便于异步仿真 )
        - 步进: 周期
        - 功能验证

3. 重点解释
    - 为什么Cycle-based不能模拟异步电路? Event-based能模拟异步电路?
        Event-based 横坐标是 time , 仿真时只需要指定 所有时间点 发生的 事件(I) 即可, 所有逻辑会在时间线上自动完成 
        Cycle-based 横坐标是 cycle , 仿真时: 
            $$
            I_{线网} \; changes \xRightarrow{\text{eval()}}\; 线网 \; changes
            $$
            $$
            I_{记忆} \; changes \;\xRightarrow{\text{eval()}}\; {记忆} \; changes
            $$
            适合同步电路(只需要功能验证, 不需要考虑时序)
        
        ==具体为什么不能模拟异步电路我也不完全太清楚, 但是基本上可以知道用于异步电路也不方便==
