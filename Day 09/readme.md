# Reverse Words

Difficulty: **Easy** <br>
Tags: **String** <br>
Solution: **[cpp](reverseWords.cpp)** <br>

Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

**Note:** The last character has not been '.'. 

**Examples :**

**Input:** *str* = `i.like.this.program.very.much` <br>
**Output:** `much.very.program.this.like.i` <br>
**Explanation:** After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i

**Input:** *str* = `pqr.mno` <br>
**Output:** `mno.pqr` <br>
**Explanation:** After reversing the whole string , the input string becomes mno.pqr

**Expected Time Complexity:** `O(|str|)` <br>
**Expected Auxiliary Space:** `O(|str|)` <br>

**Constraints:**  
1 <= |str| <= 10^5


## Approach


The main idea is to break the string into words, reverse the order of the words, and then rejoin them using dots.

#### Step-by-Step Process:

1. **Split the String into Words:**
   The first task is to split the string into individual words. We can use the `.` as the delimiter. In C++, the `getline()` function with a custom delimiter can help split the string by `.`.

   - Example: `"i.like.this.program.very.much"` becomes `["i", "like", "this", "program", "very", "much"]`.

   **Code snippet:**
   ```cpp
   stringstream ss(str); // Create a stringstream object from the input string
   string word;
   vector<string> words;

   // Extract words separated by '.'
   while (getline(ss, word, '.')) {
       words.push_back(word);
   }
   ```

   Here, we use a `stringstream` object to read the string, and `getline(ss, word, '.')` extracts substrings (words) based on the `.` delimiter. Each word is stored in the vector `words`.

2. **Reverse the Order of Words:**
   Once the string is split into individual words, we need to reverse the order of these words. This is simple in C++ using a `for` loop to traverse the vector from the last word to the first.

   - Example: `["i", "like", "this", "program", "very", "much"]` becomes `["much", "very", "program", "this", "like", "i"]`.

   **Code snippet:**
   ```cpp
   string result;
   for (int i = words.size() - 1; i >= 0; i--) {
       result += words[i]; // Append the word to result
       if (i != 0) {
           result += '.'; // Add a dot between words, except after the last word
       }
   }
   ```

   Here, we concatenate the words from the vector in reverse order into the result string. We add a `.` after each word except for the last word.

3. **Return the Resulting String:**
   The final string contains all the words in reversed order with the original dots in between. We return this result.

   - Example: The reversed order for `"i.like.this.program.very.much"` becomes `"much.very.program.this.like.i"`.



<br>
<details>
<summary>Example Walktrough</summary>

1. **Input:** `"i.like.this.program.very.much"`
   - Step 1: Split into words → `["i", "like", "this", "program", "very", "much"]`
   - Step 2: Reverse the order → `["much", "very", "program", "this", "like", "i"]`
   - Step 3: Form the final string → `"much.very.program.this.like.i"`

2. **Input:** `"pqr.mno"`
   - Step 1: Split into words → `["pqr", "mno"]`
   - Step 2: Reverse the order → `["mno", "pqr"]`
   - Step 3: Form the final string → `"mno.pqr"`

This approach efficiently handles strings of up to the maximum constraint of \(10^5\) characters.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
string reverseWords(string str) {
    // code here
    vector<string> words;
    string word;
    stringstream ss(str);

    // Split the string by '.' and store words in the vector
    while (getline(ss, word, '.')) {
        words.push_back(word);
    }

    // Reverse the order of words and form the result string
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) {
            result += '.';
        }
    }

    return result;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

#### Time Complexity:
- **Splitting the String:** The time complexity of splitting the string is `O(n)`, where `n` is the length of the string. This is because each character is processed exactly once.
- **Reversing the Words:** Once we have all the words, reversing the vector and concatenating the result also takes `O(n)` time because we need to traverse each word to form the final string.
- Therefore, the overall time complexity is `O(n)`.

#### Space Complexity:
- **Auxiliary Space:** We use extra space to store the words in a vector. In the worst case, we need space proportional to the number of characters in the string, i.e., `O(n)`.
</details>

