# chapter 4 Phaser

## functionality of phaser
在词法分析器的基础上，判断给定的句子是否是符合文法的, 如下
$$

S \to xAy \\
A \to **|* \\
S \implies xAy \implies x*y
$$
## some problem
- backtrace
- infinate recursion
## Optimize (LL 分析法)
- eliminate direct Left recurison 

    if we has
    $$
    P \to P \alpha | \beta\\
    $$
    we could modified as 
    $$
    P \to \beta P' \\
    P' \to \alpha P' | \varepsilon
    $$

- eliminate normal Left recurison 
    $$
    S \to Qc | c \\
    Q \to Rb | b \\
    R \to Sa | a \\
    S \implies Rbc  \implies Sabc  \text{ dlr } 
    $$
- eliminate backtrace
    - First set
    $$
    \text{First} (\alpha) = \{ a | \alpha \implies a.. , a \in V_T \}\\
    a \text{是} \alpha \text{所有可能推导的 字 的 第一个非终结符}  
      
    $$
    - extrace left factor (防止 first set 两两相交)
    - 如果 一个文法 已经 **不含** 左递归，
    且 first set 两两 **不** 相交，那么我们对这个文法能进行有效的自上而下
    的语法分析吗？
        - 不是的，如果包含first set 包含空字的话 需要再次进行处理

    - Follow set (properly handle $\varepsilon$ )
        $$
        \text{Follow}(A) = \{ a | S \implies ..Aa.., a\in V_T    \}  \\
          a 是在文法G中，所有紧跟在A后的终结符   
        $$
        - 当非终结符A面临输入符号a, 且$\varepsilon \in  first(\alpha _i) \wedge a \notin  first(A)$ 时，
        则当且仅当 $a \in follow(A)$时，可以使用空字替换 (注：$A \to \alpha _i ..$)






