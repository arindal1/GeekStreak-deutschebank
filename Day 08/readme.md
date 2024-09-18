# Parenthesis Checker

Difficulty: **Easy**
Tags: **Stack**, **String**
Solution: **[cpp](parenthesisChecker.cpp)**

Given an expression string **x**. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.  
For example, the function should return '*true*' for **exp** = `[()]{}{[()()]()}` and '*false*' for **exp** = `[(])`.

**Note:** The **driver code** prints "balanced" if function return true, otherwise it prints "not balanced".

**Examples :**

**Input**: `{([])}` <br>
**Output**: `true` <br>
**Explanation**: `{ ( [ ] ) }` - Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.

**Input**: `()` <br>
**Output**: `true` <br>
**Explanation**: `()` - Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.

**Input**: `([]` <br>
**Output**: `false` <br>
**Explanation**: `([]` - Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.

**Expected Time Complexity**: `O(|x|)` 
**Expected Auxilliary Space**: `O(|x|)`
  
**Constraints:**  
1 ≤ |x| ≤ 10^5


## Approach
#### - Using a Stack

1. **Initialization**:
   - Create an empty stack. The stack will be used to keep track of opening brackets.

2. **Iterate Through the Expression**:
   - Loop through each character in the string `x`.

3. **Handle Opening Brackets**:
   - When you encounter an opening bracket (`{`, `[`, or `(`), push it onto the stack. This is because we need to remember that this type of bracket has been encountered and will need to be matched with a corresponding closing bracket later.

4. **Handle Closing Brackets**:
   - When you encounter a closing bracket (`}`, `]`, or `)`), do the following:
     - Check if the stack is empty. If the stack is empty, it means there is no corresponding opening bracket for the current closing bracket, so the expression is not balanced.
     - If the stack is not empty, pop the top element from the stack. This top element represents the most recent unmatched opening bracket.
     - Check if the popped element matches the type of the current closing bracket. For example, if the current closing bracket is `}`, the popped element should be `{`. If it does not match, the expression is not balanced.

5. **Final Check**:
   - After processing all characters in the string, check if the stack is empty:
     - If the stack is empty, it means all opening brackets had matching closing brackets in the correct order, so the expression is balanced.
     - If the stack is not empty, it means there are unmatched opening brackets remaining, so the expression is not balanced.

<br>
<details>
<summary>Example Walkthrough</summary>
<br>

Consider the string `{([])}`:

1. **Processing `{`**:
   - Stack: `{`
   - Push `{` onto the stack.

2. **Processing `(`**:
   - Stack: `{ (`
   - Push `(` onto the stack.

3. **Processing `[`**:
   - Stack: `{ ( [`
   - Push `[` onto the stack.

4. **Processing `]`**:
   - Stack: `{ ( [`
   - Pop the top of the stack (`[`). The closing bracket `]` matches the opening bracket `[`, so the match is successful.

5. **Processing `)`**:
   - Stack: `{ (`
   - Pop the top of the stack (`(`). The closing bracket `)` matches the opening bracket `(`, so the match is successful.

6. **Processing `}`**:
   - Stack: `{`
   - Pop the top of the stack (`{`). The closing bracket `}` matches the opening bracket `{`, so the match is successful.

7. **End of String**:
   - Stack: empty
   - Since the stack is empty and all brackets matched correctly, the expression is balanced.

</details>



<br>
<details>
<summary>Code</summary>
<br>

```cpp
#include <iostream>
#include <stack>
#include <string>

bool ispar(const std::string &x) {
    std::stack<char> s;  // Stack to keep track of opening brackets
    
    // Iterate through each character in the string
    for (char c : x) {
        // If the character is an opening bracket, push it onto the stack
        if (c == '{' || c == '(' || c == '[') {
            s.push(c);
        }
        // If the character is a closing bracket
        else {
            // Check if the stack is empty (no matching opening bracket)
            if (s.empty()) return false;
            
            // Pop the top of the stack (the most recent unmatched opening bracket)
            char top = s.top();
            s.pop();
            
            // Check if the popped opening bracket matches the current closing bracket
            if (c == '}' && top != '{') return false;
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    
    // If the stack is empty, all opening brackets had matching closing brackets
    return s.empty();
}

int main() {
    std::string exp;
    std::cin >> exp;
    if (ispar(exp)) {
        std::cout << "balanced" << std::endl;
    } else {
        std::cout << "not balanced" << std::endl;
    }
    return 0;
}
```
</details>


<br>
<details>
<summary>Time and Space Complexity</summary>
<br>

- The **time complexity** of this approach is `O(|x|)`, where `|x|` is the length of the string. This is because each character in the string is processed once, and stack operations (push and pop) are `O(1)`.

- The **space complexity** is also `O(|x|)` in the worst case.
</details>




