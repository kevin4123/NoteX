## **Informal Idea**
PS/2(async)->下游

## **Spec**
```go 
Module{
(Inline)ps2_keyboard_sampling: 同步采样信号
ps2_keyboard_buffer: 存一帧
ps2_keyboard_fifo: 存7帧
}
```
```go
Port(PS2)(async){
    PS2{ps2_clk↓,ps2_data↓},
}
->Port(){
    System{clk↓,clrn↓},
    Data{data↓},
    Handshake{ready↓,nextdata_n↑},
    Indicator{overflow↓}
}
```
```go
Dataflow: PS2{ps2_data}→ps2_keyboard_buffer→ps2_keyboard_fifo
```
## **SubModule**
### (Inline)ps2_keyboard_sampling
```go
```
### ps2_keyboard_buffer
```go
Port(){
    Data{ps2_data↓(async)},
    Control{sampling}
}
->Port(){
    System{clk,clrn},
    Data{buffer_data},
    Control{buffer_valid},
}
```
```go
// Data Structure
[9:0] buffer;
count;(>= 0 && <= 10)

// Upadate Layer
Init:
    count = 0;
transition:
    event(sampling)->{
        {移位保存 ps2_data↓ 到 buffer},
        {count++},
        if full
            count = 0;
    }

// Flag Layer
full = count==10;
check = (buffer[0] == 0)    && 
        (ps2_data)          &&
        (^buffer[9:1])

// Event Layer
event(sampling)

// Output Layer
buffer_data = buffer[8:1];
buffer_valid = full && sampling && check;
```

### ps2_keyboard_fifo
```go
Port(){
    Data{buffer_data↓},
    Control{buffer_valid↓}
}
->Port(){
    System{clk,clrn},
    Data{data↓},
    Handshake{ready↓,nextdata_n↑},
    Indicator{overflow↓},
}
```
```go
Dataflow: Data{buffer_data↓}→fifo→Data{data↓}
```
```go
// Data Structure
[7:0] fifo[7:0];
[2:0] w_ptr,r_ptr;
[3:0] count;(>= 0 && <= 8)
// Upadate Layer
Init:
    w_ptr = 0;r_ptr = 0;count = 0;overflow = 0;
transition:
    case{event(push),event(pop)}:
        10:

        01:
        11:

// Flag Layer
empty = count==0;

// Event Layer
event(push) = buffer_valid;
event(pop) = Handshake{ready↓,nextdata_n↑};

// Output Layer
ready↓ = !empty;
data↓ = fifo[r_ptr];
```
## **Timing**

| signal | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| a |  |  |  |
| b |  |  |  |
| c |  |  |  |

## **Noun**
Message;Event;Request;Packet;Frame;Signal;
Control;Handshake;Indicator;Data;
## **Arrow**
↑ ↓ ← →
## **Formal language**
𝓘𝓲 𝓦𝔀 𝓢𝓼 𝓞𝓸
𝓢⁺=Δ(𝓢,𝓘)
