# <center><font color="rgba(146, 15, 233, 0)">Markdown Syntax</font></center>

## 二级标题

### 三级标题

0. 引用
    >引用文本
    >>引用文本
    >>>引用文本

1. 无序列表
    - 列表1
    + 列表2
    * 列表3

2. 有序列表
    1. 列表1
    2. 列表2
    3. 列表3

3. TodoList
    - [ ] 未完成
    - [x] 已完成

4. 表格
    | 左对齐 | 居中对齐 | 右对齐 |
    | :--- | :---: | ---: |
    | a | b | c |

5. 分割线
    
    ---
    *** 

6. 字体
    **粗体文本**
    *斜体文本*
    ~~删除线~~
    ==高亮文本==
    <u>下划线文本</u>

7. 图片
    ![logo](https://www.latex-project.org/img/latex-project-logo.svg)

8. 链接
    [文档](https://www.latex-project.org/help/documentation/)

9. 脚注
    - FootNote[^1]
    
10. 引用
    > 引用文本
    >> 引用文本

11. 代码块

`print("Hello World")`

```c
#include <stdio.h>
int main() {
    printf("Hello World");
    return 0;
}
```

12. Latex
    1. 内联公式
        $E=mc^2$
    
    2. 独立公式
        - **$$** 或者 **\[\]**
        - matrix
            \[
            \begin{Bmatrix}
            a + b = c \\
            x + y = z
            \end{Bmatrix}
            \]
        - overbrace
            \[
            \overbrace{
            \begin{matrix}
            a + b = c \\
            x + y = z
            \end{matrix}
            }^{\text{第一组}}
            \]
        - qquad
            \[
            \overbrace{
            \begin{matrix}
            a + b = c
            \end{matrix}
            }^{\text{第一组}}
            \qquad
            \overbrace{
            \begin{matrix}
            x + y = z
            \end{matrix}
            }^{\text{第二组}}
            \]
        - underbrace
            \[
            \underbrace{
            \overbrace{
            \begin{matrix}
            a + b = c
            \end{matrix}
            }^{\text{第一组}}
            \qquad
            \overbrace{
            \begin{matrix}
            x + y = z
            \end{matrix}
            }^{\text{第二组}}
            }_{\text{全部两条公式}}
            \]
        - right
            \[
            \left.
            \begin{aligned}
            a + b &= c \\
            x + y &= z
            \end{aligned}
            \right\}
            \]
        - left
            \[
            \begin{aligned}
            &\left\{
            \begin{aligned}
                S = \{Q_1,Q_2,Q_3\} \\
                S_{next} = next(S,I)
            \end{aligned}
            \right. \\[6pt]
            &\left\{
            \begin{aligned}
                O = out(S,I) \\
                net1 = f() \\
                net2 = g() \\
                net3 = p() \\
                net4 = q()
            \end{aligned}
            \right.
            \end{aligned}
            \]

[^1]: FootNote

---

