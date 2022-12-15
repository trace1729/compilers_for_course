# lec 08

## some words to know
| words           | meanings                   |
|-----------------|----------------------------|
| begin a string  | 开始一个串->一个串的首字母 |
| derived from    | 由某某推导出               |
| with respect to | 考虑到                     |

## 预测分析程序
- 预测分析程序有啥用
    - 预测分析表可用一个矩阵表示
    - E[A, a] 的结果要么告诉我们 遇到A时，应采用的候选
    - 要么告诉我们 句子出错了

- 程序如何操作

    设$X$ 为栈顶元素, a 储存了当前字符
    - 若 X 为 为终端元素,且X == a

$$
E \implies TE' \\
E' \implies +TE' | \varepsilon \\
T \implies FT' \\
T' \implies *FT' | \varepsilon \\
F \implies (E)|i 
$$

## 如何求 first 集合
- 定义 

## 如何求 follow 集合
- 定义：$\text{Follow}(X)= \{t | S \overset{*}{\to} \beta X t \delta \}$ 
    - if $X \to AB$ then First$(B) \subseteq$ Follow$(A)$ and 
    Follow$(X) \subseteq$ Follow$(B)$  
    - follow$(A)$ 
     > 
    - if $B \overset{*}{\to} \varepsilon$ then
    Follow$(X) \subseteq$ Follow$(A)$ 


## 如何做表
- 对文法G的每个产生式$A \to \alpha$ 执行以下两步
    - 对于每个终结符$a \in first(\alpha)$, 把$A \to \alpha$ 放入$M[A, a]$中 
    - 如果$\varepsilon \in first(\alpha)$  那么 $\forall b \in follow(A)$ 
    把$A \to \alpha$ 放进 $M[A, b]$ 
    - 把所有未定义的$M[A, a]$ 标为出错 


|   | i    | +    | *    | **(** | **)** | $\varepsilon$ |
|---|------|------|------|-------|-------|---------------|
| E | <++> | <++> | <++> | <++>  | <++>  | <++>          |
| E' | <++> | <++> | <++> | <++>  | <++>  | <++>          |
| T | <++> | <++> | <++> | <++>  | <++>  | <++>          |
| T' | <++> | <++> | <++> | <++>  | <++>  | <++>          |
| F | <++> | <++> | <++> | <++>  | <++>  | <++>          |


## readings

给定一个含有 终结符和非终结符的串$\gamma$ first($\gamma$) 是 所有 由 $\gamma$ 所推导出
表达式的第一个终结符集合。

如果两个不同的产生式$X \to \gamma _1 \quad X \to \gamma _2$ 具有相同的LHS，但是RHS 的 first 集合重叠了，
那么这个文法就不能正确的被翻译，因为对于一个终端符号I，如果它在两个集合中，那么翻译器在
接受到I这个终端符号时，会不知道使用哪一个产生式

first 集合的计算看上去十分简单：如果$\gamma = XYZ$, 那么似乎 $Y$, $Z$ 好像被忽略了，
唯一重要的就是$first(X)$, 其实并非如此，因为$X$, $Y$, $Z$ 都可能为空 

所以我们发现 first(XYZ) 集合必须包括 first(Z)。所以在计算first 集合时
我们需要跟踪哪一个符号可能产生空字 这种叫做 可空的 符号，而且我们必须
跟踪 跟随在可空字符后面的符号

- 一些定义
    - nullable(X):X 可以推导出空字
    - first($\gamma$): 由$\gamma$ 所推导出的 串的第一个终结符集合
    - follow(X): 可以紧跟在X 后的终端符号集合，这意味着
    如果$t \in follow(x) \iff 一些产生式包含了
    XYZt 且Y, Z 都是 nullable$ 

对于 以上三个属性的精确定义是因为，他们是能维持以下性质的最小集合
```python
for each production X -> Y_1Y_2...Y_k:
    for i, j in range(1, k), range(i+1, k):
        if all the Y_i is nullable:
            X is nullable
        if Y_1 .. Y_{i_-1} is nullable:
            first(X) +=  first(Y_i) # 产生式的后部为 可空
        if Y_{i+1} .. Y_{k} is  all nullable
            follow(Y_i) += follow(X) # 产生式的后部为 不可空
        if Y_{i+1} .. Y_{j-1} is nullable:
            follow(y_i) += first(y_j)
```


## some examples
给定下列文法
$$
E \implies TE' \\
E' \implies +TE' | \varepsilon \\
T \implies FT' \\
T' \implies *FT' | \varepsilon \\
F \implies (E)|i 
$$

```
我们首先计算 first(E) 
首先看 产生式的 LHS, 发现只有第一个产生式的LHS 是E，那我们关注第一个就够了。
显然 first(E) will be the superset of first(T), so we will look at first(T)
Then first(T) will be superset of first(F),
first(F) = {(, i}, which not equal to null, therefore
first(E) = first(T) = first(F) = {(, i}



```
```
follow set:
follow (E) += {$}(since it is a start symbol)
we want to figure out follow(E), apparantly E only appears in 5th
producton's RHS, then since ) follows E, and first()) = {)} != null
so follow(E) = {$, )} it is done

need to mention that if first()) is null (just assume, it is impossibe)
the follow(E) will also need to add the follow(F)
```

<++>
