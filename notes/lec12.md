# 第十二次课 
## 算符优先文法
如何识别可规约的串？我们先引入一些概念
- `素短语`  是一个短语，最少包含一个终结符，它的子集不是素短语
- `最左素短语` 

## 算符优先分析算法
使用一个符号栈，自左向右扫描串
- 如果栈顶符号的优先级小与或者等于..则做`shift`操作
- 如果 大于, 则做`reduce` 操作

如何规约呢?
- 自栈顶向下，寻找最左素短语

some example

$$
\begin{align*}
&E \to E + T | T\\
&T \to T *  F | F\\
&F \to (E) | i\\
\end{align*}
$$

判断i + i * i是否符合该文法

the whole process

| stack (b to T) | 串 | 移进 还是 规约   |
|----------------|----|------------------|
| #              | i  | # < i. so shift  |
| #i             | +  | i > +. so reduce |
| #F             | +  |                  |
| #F+            | i  | + < i. so shift  |
| #F+i           | *  | i > *. so reduce |
| #F+F           | *  |                  |
| #F+F*          | i  | * < i. so shift  |
| #F+F*i         | #  | i > #. so reduce |
| #F+F*F         | #  | reduce           |
| #F+T           | #  | reduce           |
| #E             | #  | #E# 结束         |

## LR 分析法

