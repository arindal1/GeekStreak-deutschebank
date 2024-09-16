# Longest Valid Parenthesis

Difficulty: **Hard** <br>
Tags: **Stack** <br>
Solution: **[cpp](longestValidParenthesis.cpp)** <br>


Given a string **str** consisting of opening and closing parenthesis '**(**' and '**)**'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

- For every opening parenthesis, there is a closing parenthesis.
- Opening parenthesis must be closed in the correct order.

<br>

**Examples :**

**Input:** str = ((() <br>
**Output:** 2 <br>
**Explaination:** The longest valid parenthesis substring is "()". <br>

**Input:** str = )()()) <br>
**Output:** 4 <br>
**Explaination:** The longest valid parenthesis substring is "()()". <br>

**Expected Time Complexity:** `O(|str|)`  
**Expected Auxiliary Space:** `O(|str|)`

**Constraints:**
1 ≤ |str| ≤ 10^5  


## Approach

We use a **stack** to keep track of the indices of the parentheses. By doing this, we can calculate the length of valid substrings as we encounter closing parentheses.

### Step-by-Step Explanation:

1. **Initialize a Stack:**
   - We create a stack to store indices. This helps to calculate the length of valid parentheses.
   - We push an initial value of `-1` onto the stack to act as a base for calculating valid lengths. This base is necessary to handle edge cases when the valid substring starts from the first character.

   ```cpp
   stack<int> s;
   s.push(-1);  // Base index for valid parentheses
   ```

2. **Iterate Over the String:**
   - We loop through the string character by character, examining whether it is an opening `'('` or a closing `')'`.

3. **If the Current Character is `'('`:**
   - If the character is an opening parenthesis `'('`, push its index onto the stack. We store indices instead of characters so that we can calculate the length later.

   ```cpp
   if (str[i] == '(') {
       s.push(i);  // Push index of '('
   }
   ```

4. **If the Current Character is `')'`:**
   - If the character is a closing parenthesis `')'`, we need to check if there’s a corresponding `'('` in the stack.
   - We pop the top of the stack, which corresponds to the index of the last unmatched `'('`.
     - If the stack is **not empty** after the pop, it means we have found a valid pair of parentheses. The current valid substring length is `i - s.top()`. We update the maximum length (`maxLen`).
     - If the stack is **empty** after the pop, it means the current `')'` does not have a matching `'('`. We then push the current index `i` as the new base for the next potential valid substring.

   ```cpp
   else {
       s.pop();  // Pop the top
       if (!s.empty()) {
           maxLen = max(maxLen, i - s.top());
       } else {
           s.push(i);  // Base for next valid substring
       }
   }
   ```

5. **Updating Maximum Length:**
   - Every time we find a valid substring, we calculate its length by subtracting the index at the top of the stack from the current index `i`. This gives us the length of the valid substring from the most recent unmatched `'('` to the current `')'`.
   - We keep track of the longest valid substring encountered during the iteration.

6. **Return the Result:**
   - After finishing the iteration, `maxLen` holds the length of the longest valid substring of parentheses.

<br>
<details>
<summary>Example Walkthrough</summary>

Let’s walk through an example with the string `")()())"`:

1. Start with an empty stack: `s = [-1]` (base index).
2. **i = 0**: The character is `')'`, and we pop the stack, leaving it empty. We push the current index `0` as the new base: `s = [0]`.
3. **i = 1**: The character is `'('`, so we push its index: `s = [0, 1]`.
4. **i = 2**: The character is `')'`, so we pop the stack, matching it with `'('` at index 1. Now, we calculate the valid substring length as `i - s.top()` → `2 - 0 = 2`. Update `maxLen = 2`.
5. **i = 3**: The character is `'('`, so we push its index: `s = [0, 3]`.
6. **i = 4**: The character is `')'`, so we pop the stack, matching it with `'('` at index 3. Calculate the valid substring length as `i - s.top()` → `4 - 0 = 4`. Update `maxLen = 4`.
7. **i = 5**: The character is `')'`, and we pop the stack, leaving it empty. We push the current index `5`: `s = [5]`.

At the end, `maxLen` is 4, which is the length of the longest valid parentheses substring `()()`.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int maxLength(string& str) {
    stack<int> s;
    s.push(-1);  // Base index for valid parentheses
    int maxLen = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(i);  // Push index of '('
        } else {
            s.pop();  // Pop the top
            if (!s.empty()) {
                maxLen = max(maxLen, i - s.top());
            } else {
                s.push(i);  // Base for next valid substring
            }
        }
    }
    return maxLen;
}

int main() {
    string str = ")()())";
    cout << maxLength(str) << endl;  // Output: 4
    return 0;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **O(n)**: We traverse the string once (O(n)) and perform push and pop operations on the stack, each of which takes O(1). Hence, the overall time complexity is O(n), where n is the length of the string.

- **O(n)**: In the worst case, the stack can store up to n indices, so the space complexity is O(n).
</details>