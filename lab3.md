# 编译原理实验三 消除左递归
## eliminate direct recursion
```
non_rec_set
rec_set
for each non-terminal Nt (1)
    for each production P start with Nt(2)
        if LHS of P == the first symbol of RHS of P
            left recursion exists
            add to rec_set
        else add to non_rec_set
    if rec_set.size > 0:
        new_non_terminal = generate_non_terminal()
        for each item in non_rec_set:
            modify the RHS by: RHS := RHS + new_non_terminal
        for each item in rec_set
            modift the RHS by: RHS := RHS[1:] + new_non_terminal
```
\varepsilon  

## eliminate indirect recursion
for all non-termials in a Grammer, we label name from 1 to n,
n denotes the number of all non-terminals

```
for i in 1..n
    for j in 1..n
       (1) find production A_i -> A_j gammer
        replace it by A_i -> \sum delta_i gammer
        delta_i would be all the RHS of A_j
       (2)
        if new production have direct left recursion
        elinate it

        void do_substitution() {
            1. remove A_i -> \sum delta_i gammer, stores it
            in a string s.
            2. for each production belongs to delta_j, we
            reassemble it with the rest of RHS of A_i's production.
            store them into A_i's production.
        }
```
How to store the value of the non-termial
- store them as char
    - a little hard to represant B prime
    - no problem, using 'B' - 27 as the new
- store them as string
    - it is hard to do comparsion
    
## example about eliminating indirect recursion 


| j\i  | 1 ( R ) | 2 (Q)           | 3 (S)             |
|------|-------|-----------------|-------------------|
| 1( R ) | j > i | 存在$Q \to R$吗 | 存在$S \to R$吗   |
| 2(Q) | j > i | j > i           | 存在 $S \to Q$ 吗 |
| 3(S) | j > i | j > i           | j > i             |
