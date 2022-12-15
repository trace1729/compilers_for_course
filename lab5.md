# LR 分析器
The LR parser can be implemented as follows:
- First, store the Action table and Goto table

```cpp
bool LR_parser(acion, goto_, input):
    stack<> symbol
    state := 0
    idx = 0
    while (idx < input.length() && !stack.empty()) :
       act = action[state, input[idx]]
       switch(act.action) {
            case SHIFT:
                state = act.content
            case REDUCE:
                do act.content
                state = goto_[state, nt]
            case ACC:
                return true
            case ERROR:
                return false
       }

```
we can use a function `look_up_table` for 
goto and action, since they both takes same arugment.
and both return the same type -- action.
action is a pair of 
<++>
