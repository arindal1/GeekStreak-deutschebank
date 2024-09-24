### Smallest window in a string containing all the characters of another string

Difficulty: **Hard** <br>
Tags: **Sliding Window**, **Array** <br>
Solution: **[cpp](smallestWindow.cpp)**

Given two strings **s** and **p**. Find the smallest window in the string **s** consisting of all the characters(**including duplicates**) of the string **p**.  Return "**-1**" in case there is no such window present. In case there are multiple such windows of same length, return the one with the **least starting index**.  
**Note** : All characters are in Lowercase alphabets. 

**Examples:**

**Input: s** = `"timetopractice"`, p = `"toc"` <br>
**Output:** `toprac` <br>
**Explanation: "toprac" is the smallest
substring in which "toc" can be found.

**Input:** s = `"zoomlazapzo"`, p = `"oza"` <br>
**Output:** `apzo` <br>
**Explanation:** "apzo" is the smallest 
substring in which "oza" can be found.

**Expected Time Complexity:** `O(|s|)`  
**Expected Auxiliary Space:** `O(n)`, n = `len(p)`

**Constraints:**   
1 ≤ |s|, |p| ≤ 10^5


### Approach

The problem involves finding the smallest window in a string `s` that contains all the characters of another string `p`, including duplicates. To solve this, we use a **sliding window technique** to dynamically expand and contract the window, and we keep track of the frequency of characters inside the window.

**Key steps**:
1. **Character Frequency Tracking**:
   - We maintain two arrays of size 128 (for ASCII characters) to track the frequency of characters in the pattern `p` and the current window in string `s`.
   - The idea is to track how many characters we need and compare them to how many we have in the current window.
   
2. **Sliding Window**:
   - Start with two pointers: `start` and `end`. The `end` pointer expands the window to the right, and the `start` pointer contracts the window from the left once all required characters are in the window.
   - For each character that `end` encounters, we update the window frequency and check if it contributes to forming a valid window (i.e., if it satisfies the character frequency requirements of `p`).
   
3. **Valid Window Check**:
   - A window is considered valid if it contains all characters of `p` with the correct frequency.
   - Once a valid window is found, we attempt to minimize it by moving the `start` pointer to the right (shrinking the window) while ensuring the window still remains valid.

4. **Updating Result**:
   - As soon as a valid window is found, we compare its length with the minimum length found so far. If the new window is smaller, we update the result.

5. **Return Result**:
   - After the loop completes, if a valid window was found, return the substring. Otherwise, return `"-1"` if no such window exists.


<br>
<details>
<summary>Example Walkthrough</summary>


Let’s go through an example:

**Input**: s = `"zoomlazapzo"`, p = `"oza"`

1. **Initial setup**:
   - `pMap` is set to record the frequency of characters in `p`: `pMap['o'] = 1`, `pMap['z'] = 1`, `pMap['a'] = 1`.
   - We initialize `start = 0`, `minLength = INT_MAX`, `minStart = 0`, and `formed = 0`.

2. **Iterating through `s` with `end` pointer**:
   - At `end = 0` (s[0] = 'z'), we increase `windowMap['z']`. Since it matches `pMap['z']`, `formed` increases to 1.
   - At `end = 1` (s[1] = 'o'), we increase `windowMap['o']`. Since it matches `pMap['o']`, `formed` increases to 2.
   - At `end = 6` (s[6] = 'a'), we increase `windowMap['a']`. Now `formed` becomes 3, which means all required characters ('o', 'z', 'a') are present in the current window.
   
3. **Valid Window Detected**:
   - The current window "zoomlaz" is valid (it contains 'o', 'z', 'a'). We try to shrink it from the left:
     - At `start = 0` (s[0] = 'z'), the window still contains all required characters, so we update `minLength = 7`.
     - At `start = 1` (s[1] = 'o'), we remove 'z', making the window invalid. Now we stop shrinking.
   
4. **Continue expanding `end` pointer**:
   - At `end = 10` (s[10] = 'z'), the window becomes valid again with "apzo" as the current window.
   - We update the result to `minLength = 4`, as this is smaller than the previous valid window.
   
5. **End of Iteration**:
   - The smallest window found is `"apzo"`.
</details>


<br>
<details>
<summary>Code</summary>


```cpp
string smallestWindow(string s, string p) {
    // If s is smaller than p, no window can exist
    if (s.size() < p.size()) return "-1";

    // Create frequency maps for pattern p
    vector<int> pMap(128, 0);
    for (char c : p) {
        pMap[c]++;
    }

    // Variables for window management
    int start = 0, minLength = INT_MAX, minStart = 0;
    int required = p.size();  // Total characters to match
    int formed = 0;           // Characters matched

    // Window frequency map
    vector<int> windowMap(128, 0);

    // Sliding window
    for (int end = 0; end < s.size(); end++) {
        char c = s[end];
        windowMap[c]++;

        // If current character matches frequency in p
        if (pMap[c] > 0 && windowMap[c] <= pMap[c]) {
            formed++;
        }

        // When all characters are matched, shrink the window
        while (formed == required) {
            // Update the minimum window
            if (end - start + 1 < minLength) {
                minLength = end - start + 1;
                minStart = start;
            }

            // Shrink from the left
            char leftChar = s[start];
            windowMap[leftChar]--;
            if (pMap[leftChar] > 0 && windowMap[leftChar] < pMap[leftChar]) {
                formed--;
            }
            start++;
        }
    }

    return minLength == INT_MAX ? "-1" : s.substr(minStart, minLength);
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: The sliding window is processed in `O(|s|)`, where `|s|` is the length of string `s`.

- **Space Complexity**: We are using two frequency arrays (`pMap` and `windowMap`), each of size 128 (fixed size for ASCII characters). This gives us a space complexity of `O(1)`.

</details>

<br>

[[back to TOP](#smallest-window-in-a-string-containing-all-the-characters-of-another-string)]