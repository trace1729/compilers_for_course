# LL(1) Parser
## some hints
if you cannot find reference for funtion signature
you may forgot to include add corresponding .o file

## How to construct a first set

To start, Initialize the FIRST set for each nonterminal to the empty set.

Then from each production in a grammar, add the first set of RHS 
to the first set of LHS. How we are you going to actually do this?

```
for symbol in RHS:
    if symbol in terminal_set:
        add the symbol to first set to RHS
        stop;
    if first(symbol) contains epslion:
        first(RHS) += first(symbol)
        continue;
    else 
        first(RHS) += first(symbol)
        stop;

```

<++>

## How to construct a follow set
```
for symbol in RHS:
    if symbol in non-terminal set:
        if symbol is in the end of the RHS:
            follow(symbol) += follow(nt)
        else: 
            first_tmp = first(RHS[loc(RHS) + 1 :])
            if \varepsilon in first_tmp:
                follow(symbol) += follow(nt)
            follow(symbol) += first_tmp;


def comp_first_set_for_production
if (prod[0] is nullable) {
    return first_set[prod[0]] += comp_first_set_for_production(prod[0]) 
}
```

## How to contruct a parse table
```
for nt in non-terminal:
    for prod in production[nt]:
        if prod.RHS in not nullable:
            for each termial in first(prod.RHS):
                parse_table[nt][termial] = {nt, prod}
        else:
            for each termial in first(prod.RHS):
                parse_table[nt][termial] = {nt, prod}

            for each termial in follow(X):
                parse_table[nt][termial] = {nt, prod}
            
```


## How to tell whether a string a vaild or not
```
Initilize a stack
push Marker
push startSymbol

while stack is not empty:
    if stack.top() == MARKER:
        stack.pop()
        
    elif stack.top() is terminal 
        if terminal is the same as current character at input string
            idx ++
            stack.pop()
        else
            return false
    elif 
        if (t = table[stack.top()][input[idx]]) != null:
            for i in t.size()..0
                push(t[i]);
        else
            return false
```
## How to use scan
read a string
give it to scan, it returns a symbol array
we use a map, mapping symbol to terminal and non-terminal
give it to LL parser, see whether it is vaild or not;

