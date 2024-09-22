# Longest Prefix Suffix

Difficulty: **Hard**

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

**NOTE:** Prefix and suffix can be overlapping but they should not be equal to the entire string.

**Examples :**

**Input:** str = `"abab"` <br>
**Output:** `2` <br>
**Explanation:** `"ab"` is the longest proper prefix and suffix. 

**Input:** str = `"aaaa"` <br>
**Output:** `3` <br>
**Explanation:** `"aaa"` is the longest proper prefix and suffix. 

**Expected Time Complexity:** `O(|str|)` <br>
**Expected Auxiliary Space:** `O(|str|)` <br>

**Constraints:**  
1 ≤ |str| ≤ 10^6 <br>
**str** contains lower case English alphabets


## Approach

The key concept for solving this problem is to use the **Longest Prefix Suffix (LPS) array**, which is commonly used in the **KMP (Knuth-Morris-Pratt)** string matching algorithm. The LPS array is an array where each element `lps[i]` represents the length of the longest proper prefix which is also a proper suffix for the substring `str[0:i]`.


#### Step-by-Step Process:
1. **LPS Array**:
   - We create an LPS array of the same length as the input string. The `i-th` value in the LPS array tells us the length of the longest proper prefix which is also a suffix for the substring `str[0:i]`.
   - The LPS array helps us efficiently track this information by comparing characters in the string in a systematic manner.

2. **Initialization**:
   - `lpsArray[0] = 0` because there is no proper prefix or suffix for a single character.
   - `len` is a variable used to keep track of the current longest proper prefix suffix, starting at `0`.

3. **Iterate through the string**:
   - We start from index `i = 1` and iterate through the string, comparing the current character `str[i]` with the character at the current `len` (which is `str[len]`).

4. **Matching characters**:
   - If `str[i] == str[len]`, it means we have found a matching prefix and suffix.
     - Increment `len` by 1 because we have extended the length of the matching prefix-suffix.
     - Set `lpsArray[i] = len`, meaning that the longest proper prefix which is also a suffix for the substring `str[0:i]` has a length of `len`.
     - Move to the next character by incrementing `i`.

5. **Non-matching characters**:
   - If `str[i] != str[len]`, it means the current character does not extend the current prefix-suffix match.
     - If `len != 0`, we **backtrack** to the previous longest proper prefix-suffix by setting `len = lpsArray[len - 1]`. This reduces `len` and allows us to check if a smaller prefix-suffix is a match, without starting over.
     - If `len == 0`, we set `lpsArray[i] = 0` because there is no proper prefix-suffix at this point, and we increment `i` to move to the next character.

6. **Final Result**:
   - Once we have built the entire LPS array, the last value in the LPS array (`lpsArray[n - 1]`) gives us the length of the longest proper prefix which is also a suffix for the whole string `str`.


<br>
<details>
<summary>Example Walkthrough</summary>

#### Input 1: `"abab"`

1. **Initialization**:
   - lpsArray = `[0, 0, 0, 0]`
   - len = `0`
   - Start with `i = 1`.

2. **i = 1** ( str[1] = `'b'` ):
   - `str[1] != str[0]` ('b' != 'a'), so set `lpsArray[1] = 0`. Move to the next character.

3. **i = 2** ( str[2] = `'a'` ):
   - `str[2] == str[0]` ('a' == 'a'), so we have a matching prefix and suffix of length 1.
   - Set `lpsArray[2] = 1`. Move to the next character.

4. **i = 3** ( str[3] = `'b'` ):
   - `str[3] == str[1]` ('b' == 'b'), so the matching prefix and suffix extends to length 2.
   - Set `lpsArray[3] = 2`.

5. **Result**:
   - The LPS array is now `[0, 0, 1, 2]`.
   - The last value **lpsArray[3]** = `2` is the length of the longest proper prefix which is also a suffix.

#### Input 2: `"aaaa"`

1. **Initialization**:
   - lpsArray = `[0, 0, 0, 0]`
   - len = `0`
   - Start with `i = 1`.

2. **i = 1** ( str[1] = `'a'` ):
   - `str[1] == str[0]` ( 'a' == 'a' ), so the matching prefix and suffix is of length 1.
   - Set `lpsArray[1] = 1`.

3. **i = 2** ( str[2] = `'a'` ):
   - `str[2] == str[1]` ( 'a' == 'a' ), so the matching prefix and suffix extends to length 2.
   - Set `lpsArray[2] = 2`.

4. **i = 3** ( str[3] = `'a'` ):
   - `str[3] == str[2]` ( 'a' == 'a' ), so the matching prefix and suffix extends to length 3.
   - Set `lpsArray[3] = 3`.

5. **Result**:
   - The LPS array is now `[0, 1, 2, 3]`.
   - The last value **lpsArray[3]** = `3` is the length of the longest proper prefix which is also a suffix.

</details>

<br>
<details>
<summary>Code</summary>

```cpp
int lps(string str) {
    int n = str.length();
    vector<int> lpsArray(n, 0);  // Create LPS array to store lengths of the longest proper prefix suffix
    
    int len = 0;  // Length of previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lpsArray[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lpsArray[len - 1];  // Backtrack to check the previous longest prefix suffix
            } else {
                lpsArray[i] = 0;
                i++;
            }
        }
    }

    return lpsArray[n - 1];  // The last value in lpsArray gives the longest proper prefix which is also a suffix
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: The algorithm processes each character of the string exactly once, making it an `O(n)` solution, where `n` is the length of the input string.
- **Space Complexity**: The space complexity is `O(n)` due to the LPS array used to store the prefix-suffix lengths.
</details>