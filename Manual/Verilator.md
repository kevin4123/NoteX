## Verilator

1. **简介**
    - [Verilator](https://www.veripool.org/verilator/)
    - Verilator = HDL Compiler + Makefile generator

2. **Verilator**
    1. **verilator Arguments**
        - --x-assign 0: converts all Xs to 0s
        - --x-initial 0: initializes all otherwise uninitialized variables to zero
        - -Wall: Enable all style warnings
        - --trace-vcd: Enable VCD waveform creation
        - --MMD: Create .d dependency files
        - -O3: High-performance optimizations
        - --Mdir <directory>: Name of output object directory
        - --top-module <topname>: Name of top-level input module
        - --cc: Create C++ output
        - --exe: Link to create executable,defaults is create library
        - -CFLAGS <flags>: C++ compiler arguments for makefile
        - -LDFLAGS <flags>: Linker pre-object arguments for makefile
        - -Wno-{warning-code}: Disable warnings

    2. **Simulation Runtime Arguments**
        - +verilator+rand+reset+<value>
        - 
    3. **Language Extensions**
        - /* verilator public_flat_* */
            - $\{记忆, 线网_{Internals}\}$ 好像都在 dut->rootp里面, 我没有加这个扩展, 依然可以访问Internals
        - /* verilator public */
            - 类似作用
