**Informal Idea**

**Formal Spec**
```go
    Port(System)={}
    Port()={
    }
```
**Refine(Decomposition)**

**Implementation**
```go
Description:
Update_Layer(更新层)
𝓢={
}
Init:
Transition:
    
Indicator_Layer(指示层)
Indicator={
}

Output_Layer(输出层)
𝓞={
}
```
**Dependency** Root: 𝓢,𝓘
```go
```
**Invariant**
```go
```

**Timing**
| signal | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| a |  |  |  |
| b |  |  |  |
| c |  |  |  |

========================================
**Noun**
Message;Event;Request;Packet;Frame;Signal;
Control;Handshake;Indicator;Data;
**Arrow**
↑ ↓ ← →
**Formal language**
𝓘𝓲 𝓦𝔀 𝓢𝓼 𝓞𝓸
𝓢⁺=Δ(𝓢,𝓘)
