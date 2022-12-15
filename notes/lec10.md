# LR Paring
## words
| words     | meanings |
|-----------|----------|
| augmented | 增加     |

LL(k) 文法的缺点在于他们必须预测所使用的产生式，且只查看ss产生式右端的前1个字符 

LR(k): left-right parse, Rightmost derivation, k-token lookahead

## Lead in example
$$
S \to aAcBe \\
A \to b\\
A \to Ab\\
B \to d
$$

把输入符号串$abbcde$ 归约到开始符号S.

| stack(bottom to up) | input  | production    |
|---------------------|--------|---------------|
| empty               | abbcde |               |
| a                   | bbcde  |               |
| ab                  | bcde   |               |
| aA                  | bcde   | $A \to b$     |
| aAb                 | cde    |               |
| aA                  | cde    | $A \to Ab$    |
| aAc                 | de     |               |
| aAcd                | e      |               |
| aAcB                | e      | $B \to d$     |
| aAcBe               | null   |               |
| S                   | null   | $S \to aAcBe$ |


How can we choose production, Let us introduce LR parsing engine

A BU parser traces a rightmost derivation in reverse

- 自顶向下算法过程倒过来就是最右推导


## 规约算法
画出语法分析树

- `短语` 将语法分析树中高度大于等于1的子树的叶子节点连接起来，就是短语
- `直接短语`将语法分析树中高度等于1的子树的叶子节点连接起来，就是直接短语
- `句柄(handle)` 在最左端的直接短语


## 算符优先分析
$$
a <. b\\
a =. b\\
a >. b
$$
`算符文法`: 任何一个产生式的右端都不会有两个连续的非终结符
`算符优先文法`:
