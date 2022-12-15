# Lec 06
## 正规文法 < = > NFA
### 右线性文法 
给定右线性正规文法$G_R = <V_T, V_N, S , P>$(非终端，终端，开始符号，产生式)，按以下步骤转换
- for every elem $\in V_N$, treat it as a new state
- add a new **final**  state **f** 
    - if some prodution in **P** contains synax like $A \to a$ ,this is(由非终端符号直接推出终结符), 
    we add an edge which starts from **A** ,  end with **f**
    and labeled **a** in our NFA
    - for $\forall A \in V_N, a \in V_T$ if **P** contains some production like$A \to aA_1 | aA_2 | 
    \cdots |aA_n$ (非终端符号在右), then we add n edges 
     which starts from **A** ,  end with $A_i$ and labled **a**  

> 如何从 NFA 还原回右线性文法呢？
> 只需要关注每一个节点的出度就行，每一条边就代表一个产生式。

> 需要注意的是，去掉 我们人为加上的 终态 f

### 左线性文法 
给定左线性正规文法$G_R = <V_T, V_N, S , P>$(非终端，终端，开始符号，产生式)，按以下步骤转换
- for every elem $\in V_N$, treat it as a new state
- add a new **initial**  state **q** 
    - if some prodution in **P** contains synax like $A \to a$ ,this is(由非终端符号直接推出终结符), 
    we add an edge which starts from **q** ,  end with **A**
    and labeled **a** in our NFA
    - for $\forall A \in V_N, a \in V_T$ if **P** contains some production like
    $A_1 \to Aa, A_2 \to Aa, \cdots A_n \to Aa$ 
    (非终端符号在左), then we add n edges 
     which starts from **A** ,  end with $A_i$, and labeled with a

> 如何从 NFA 还原回左线性文法呢？
> 只需要关注每一个节点的入度就行，每一条边就代表一个产生式。

> 需要注意的是，去掉 我们人为加上的 初态 q


## 正规文法 < = > DFA
- 右线性文法中
    - 如果 $A \overset{a}{\to}B \wedge B \in F$, 除了产生式$A\to B$ 
    还要加上$A \to a$ 
## NFA => DFA
define $\varepsilon - \text{closure}$ as follows
- let **edge(s, c)** be the set of the state reachable by following 
a single edge with label c.
- **closure(S)** will be the set T, where $T = S \cup \big( \bigcup_{s \in T} edge(s, \varepsilon) \big)$ 

> 状态S的 $\varepsilon 闭包$ 就是 S经过0次或多次 $\varepsilon$ 后所能到达的
> 状态的集合

我们可以这样计算 T 

<font color='red'>注：左箭头表示赋值的意思 </font> 
$$
\begin{align*}
  &T \leftarrow S \\
  & \text{repeat } T' \leftarrow T \\
  & \qquad \; \;   T'   \cup \big( \bigcup_{s \in T} edge(s, \varepsilon) \big)  \\
  & \text{until } T = T'  
\end{align*}
$$
- define **DFAegde(d, c)** as follows

    for every element s in set d
    - first we calc edge(s, c) (see on the input c, where can it tranfer to)
    - than calc the **closure** of it (for $\varepsilon$ consume no input)
    - then sum all the results up

- then we introduce the algorithm to make an DFA
$$
\begin{align*}
   & \text{state[0]} \leftarrow \{\};   
    \text{state[1]} \leftarrow \text{closure} \{s_1\};
      \\
   & p \leftarrow 1, j \leftarrow 0 \\
   & \text{while } j \le p:\\
   &\quad \text{foreach } c \in \Sigma \\
   & \qquad e \leftarrow \text{DFAedge(states[j], c)} \\
   & \qquad \text{if } e = state[i] for some i \le p \\ 
   & \qquad \; \; \text{than trans[j, c]} \leftarrow i \\ 
   & \qquad \; \; \text{else } p += 1 \\
   & \qquad \qquad \text{state[p]} \leftarrow e \\ 
   & \qquad \qquad \text{trans[j, c]} \leftarrow p  \\
   & \text{j += 1} 

\end{align*}
$$
```
循环体：
    对 闭包中的 每一个字符c
        看 stata[j] 在 c 下 转移的状态时啥
             如果已经出现了这个状态，设它为i 
             那么就有 j ->(c) i
             否则  就产生了一个新状态j' 
             就有 j ->(c) j'
        
```

<++>

## DFA $\overset{ \text{化简}  }{\to}$ DFA 
- 首先根据是否为终态化为两大类
- 再看这两大类，在不同输入字符下的状态转移
    - 如果 对每一个 输入字符，某一类的状态转移后产生的状态集都在一个集合中
    就不再细分
    - 否则递归拆分

### some examples 
图例 为 ppt 76
- 首先由是否为终态划分为$\{1, 2, 3, 4\}$, $\{5, 6, 7\}$ 
- 看状态转移
   |   | a | b |
   |---|---|---|
   | 1 | 6 | 3 |
   | 2 | 7 | 3 |
   | 3 | 1 | 5 |
   | 4 | 4 | 6 |


   |   | a | b |
   |---|---|---|
   | 5 | 7 | 3 |
   | 6 | 4 | 1 |
   | 7 | 4 | 2 |

由于1,2 在 a 下 转移的状态为 {6,7}，我们把目光转向{6, 7}
由于{6,7} 在 a 下的转移的状态为{4, 4}, 处于相同的集合，我们再看{6, 7}
在b下转移的状态为{1,2}，顾 {1, 2}, {6, 7}相互依赖
所以{1，2}，{6, 7}都 不需要拆分。

而 3，4 在b下转移的状态为{5， 6},而 5, 6不是一个集合的({5, 6}在a下转移后的状态集合显然不同)
...所以需要拆分

- 将集合拆分后，我们需要对原图的节点进行合并。 b状态转移下 所处的状态都在一个集合内(6, 7 是一个集合的)
    - (explain how to merge)todo
