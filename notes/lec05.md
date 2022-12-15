# Regular expression
- We must determine what set of strings the token belongs to
    that's why we use regular expr

## conponents
- single charater 'c' $\{"c"\}$ 
- Epsilon 
- Union $A + B = \{a | a\in A \} \cup \{ b | b \in B \}$ 
- Concantenation $\{ ab | a \in A  \wedge b \in B \}$ 
- iteration $A* = \bigcup_{i=0} A^i$ where $A^i =\underbrace{A...A}_{i}$ 

## some examples

$(0 + 1)^{*} = \bigcup _{i=0} (0 + 1)^{i} = 
\bigcup _{i} \{1, 0\}$ 

# formal langauge (正式文法)

## conponents

- let $\sum$ be a alphabet, a language over $\sum$ is a collection
of string drawn from $\sum$ 
- Meaning function $L$ means synatx to semantcis
    $L(e) \to \text{(their meanigs)}$ 
- in regular expresion $L: \text{Exp}  \to \text{sets}$ 
    - L funtion is many to one 
