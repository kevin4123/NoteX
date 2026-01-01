## WaveDrom 速查表

1. **手动**
```wavedrom
{
signal: [
{ name: "手动",               wave: "hl" },
{ name: "手动 marked",        wave: "HL" },
]
}
```

2. **一 or 零**  
```wavedrom 
{ signal: [
{ wave: "01" },
]}
```

3. **时钟**
```wavedrom
{
signal: [
{ name: "上升沿",          wave: "p" },
{ name: "上升沿 marked",   wave: "P" },
{ name: "上升沿 period=2", wave: "p",       period: 2 },
{},
{ name: "下降沿",          wave: "n" },
{ name: "下降沿 marked",   wave: "N" },
{ name: "下降沿 period=2", wave: "n",     period: 2 },
]
}
```
3. **High Impedance & Undefined**
```wavedrom
{
signal: [
{ name: "data",     wave: "zx" },
]
}
```

4. **数据类型**
```wavedrom
{
    signal: [
        { name: "data states", wave: "023456789=0" },
        { name: "带文本",   wave: "023456789=0", data: "a b c d e f g h i" },
        {},
        { name: "带文本",   wave: "2..2..2....", data: [
            "First State",
            "Second State",
            "Third State",
        ]}
    ]
}
```

5. **省略**
```wavedrom
{
signal: [
{ name: "clk",  wave: "p|" },
]
}
```

6. **Up & Down**
```wavedrom
{
signal: [
{ name: "up",   wave: "u" },
{ name: "down", wave: "d" },
]
}
```

7. **Signal Groups**
```wavedrom
{
signal: [
[
"group",
{ name: "A", wave: "p...." },
  [
  "embed",
  { name: "B", wave: "2...." },
  { name: "C", wave: "3...." },
  ],
],

[
{ name: "D", wave: "4...." },
{ name: "E", wave: "5...." },
]
]
}
```

8. **Header & Footer**
```wavedrom
{
    signal: [
        { name: "A", wave: "2....." },
        { name: "B", wave: "3....." },
        { name: "C", wave: "4....." },
        { name: "D", wave: "5....." },
        { name: "E", wave: "6....." },
    ],
    head: {
        text: "Hello World!",
    },
    foot: {
        text: "Bye World!",
    }
}
```

9. **Cycle Enumeration Marker**
```wavedrom
{
    signal: [
        { name: "A", wave: "2....." },
        { name: "B", wave: "3....." },
        { name: "C", wave: "4....." },
        { name: "D", wave: "5....." },
        { name: "E", wave: "6....." },
    ],
    head: {
        tick: 42,
    },
    foot: {
        tock: 1,
        every: 2,
    }
}

```

10. **Edges**
```wavedrom
{ signal: [
  { name: 'A', wave: '01........0.',  node: '.a........j' },
  { name: 'B', wave: '0.1.......0.',  node: '..b.......i' },
  { name: 'C', wave: '0..1....0...',  node: '...c....h..' },
  { name: 'D', wave: '0...1..0....',  node: '....d..g...' },
  { name: 'E', wave: '0....10.....',  node: '.....ef....' }
  ],
  edge: [
    'a~b t1', 'c-~a t2', 'c-~>d time 3', 'd~-e',
    'e~>f', 'f->g', 'g-~>h', 'h~>i some text', 'h~->j'
  ]
}
```
| Identifier | Type | Property |
| :---: | :---: | :---: |
| ~ | Spline | Start and ending horizontal |
| -~ | Spline | Start horizontal |
| ~- | Spline | Ending horizontal |
| - | Sharp | Shortest path |
| + | Sharp | Shortest path with bars |
| `- | -` | Sharp |
| `- | ` | Sharp |
| ` | -` | Sharp |

11. scratchpad

```wavedrom
{
head: {
    tick: 0,
},
signal : [
    { name: "clk",  wave: "p.............................." },
    { name: "sampling",  wave: "0..1010101010101" },
    { name: "ps2_data",  wave: "0...1...0...1.." },
    {},
    { name: "buffer",  wave: "================", data: "x x x x 0 0 01 01 011 011 110 110 100 100 001 001  " },
    {},
],
}
```
