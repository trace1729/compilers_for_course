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
```
How to store the value of the non-termial
- store them as char
    - a little hard to represant B prime
    - no problem, using 'B' - 27 as the new
- store them as string
    - it is hard to do comparsion
    - 
    - 
