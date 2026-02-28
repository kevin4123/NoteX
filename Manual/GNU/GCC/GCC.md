## GCC(GNU Compiler Collection)

1. 简介
    - [GCC 官网](https://www.gnu.org/software/gcc/)
    - [GCC 手册](https://gcc.gnu.org/onlinedocs/)
    - includes front ends for C, C++, Objective-C, Fortran, Ada, Go, D, Modula-2, and COBOL as well as libraries for these languages (libstdc++,...)
    - GCC(cpp, cppinternals, gcc, gccint, gfc-internals, gfortran, gnat-style, gnat_rm, gnat_ugn, libgomp, libiberty, libstdc++)

2. gcc
    - Options
    - Common-Function-Attributes
        ```c
        // 指定函数 section
        __attribute__ ((section("section-name"))) 
        /*
        * 告诉编译器不要为这个函数生成“函数前导码(Prologue)”和“函数退出码(Epilogue)
        * 函数体中写 Basic Asm, 相当于 内联汇编 
        */
        __attribute__ ((naked))
        ```
    - Common Variable Attributes
        ```c
        // variable must be emitted even if it appears that the variable is not referenced
        __attribute__((used))
        ```

3. cpp
    1. Options
        -
    2. Predefined Macros
        - Standard Predefined Macros
            ```c
            __FILE__
            __LINE__
            __cplusplus
            ```
        - Variadic-Macros
            ```c
            // 变参宏
            #define debug(format, ...) fprintf (stderr, format, ## __VA_ARGS__)
            ```

4. 