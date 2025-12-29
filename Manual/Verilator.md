## Verilator

1. 简介
    - [Verilator](https://www.veripool.org/verilator/)
    - Verilator = HDL Compiler + Makefile generator

2. Verilator
    1. verilator Arguments
        - --x-assign fast: converts all Xs to whatever is best for performance.
        - --x-initial fast: is best for performance, and initializes all
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
        - 

    2. Simulation Runtime Arguments
        - +verilator+rand+reset+<value>
        - 