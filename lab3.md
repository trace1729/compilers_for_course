# 编译原理实验三 消除左递归
## eliminate direct recursion


## eliminate indirect recursion
for all non-termials in a Grammer, we label name from 1 to n,
n denotes the number of all non-terminals

for i in 1..n
    for j in 1..n
       (1) find production A_i -> A_j gammer
        replace it by A_i -> \sum delta_i gammer
        delta_i would be all the RHS of A_j
       (2)
        if new production have direct left recursion
        elinate it

How to store the value of the non-termial
- store them as char
    - a little hard to represeant B prime
- store them as string
    - it is hard to do comparsion
    - 
