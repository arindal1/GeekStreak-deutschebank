# Roof Top

Difficulty: **Easy** <br>
Tags: **Array**, **Greedy**, **Sliding Window** <br>
Solution: **[cpp](roofTop.cpp)**

You are given the heights of consecutive buildings. You can move from the roof of a building to the roof of the next adjacent building. You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

**Examples:**

**Input:** arr[] = `[1, 2, 2, 3, 2]` <br>
**Output:** `1` <br>
**Explanation:** 1, 2, or 2, 3 are the only consecutive buildings with increasing heights thus maximum number of consecutive steps with an increase in gain in altitude would be 1 in both cases.

**Input:** arr[] = `[1, 2, 3, 4]` <br>
**Output:** `3` <br>
**Explanation:** 1 to 2 to 3 to 4 is the jump of length 3 to have a maximum number of buildings with increasing heights, so maximum steps with increasing altitude becomes 3.

**Expected Time Complexity:** `O(n)`  
**Expected Auxiliary Space:** `O(1)`

**Constraints:**  
1 <= arr.size() <= 10^6  
1 <= arr[i] <= 10^5

---

### Approach:
The problem is to find the maximum number of consecutive steps you can take between adjacent buildings, where each step involves moving to a taller building than the previous one. Here's the detailed approach:

1. **Initialization**:
   - We initialize two variables: 
     - `current_steps`: Tracks the number of consecutive steps with increasing height.
     - `max_steps`: Keeps track of the maximum value of `current_steps` during the traversal of the array.
   
2. **Traverse the array**:
   - Start iterating from the second building (i.e., index 1) to the last building.
   - For each building at index `i`, compare its height with the previous building's height (`arr[i] > arr[i - 1]`).
   - If the current building is taller than the previous one, increase the `current_steps` by 1.
   - If not (i.e., the building at `i` is not taller), reset `current_steps` to 0, because the streak of increasing altitude has been broken.
   
3. **Update maximum steps**:
   - After each iteration, compare `current_steps` with `max_steps` and update `max_steps` if `current_steps` is larger.

4. **Return the result**:
   - After completing the loop, `max_steps` will contain the maximum number of consecutive steps where you move to taller buildings.

<br>
<details>
<summary>Example Walkthrough</summary>

#### Example 1:
Input: arr[] = `[1, 2, 2, 3, 2]`

- Start at index 1 (`arr[1] = 2`), compare with `arr[0] = 1`. Since 2 > 1, increment `current_steps` to 1.
- Move to index 2 (`arr[2] = 2`), compare with `arr[1] = 2`. Since 2 is not greater than 2, reset `current_steps` to 0.
- Move to index 3 (`arr[3] = 3`), compare with `arr[2] = 2`. Since 3 > 2, increment `current_steps` to 1.
- Move to index 4 (`arr[4] = 2`), compare with `arr[3] = 3`. Since 2 is not greater than 3, reset `current_steps` to 0.

Throughout this process, the maximum `current_steps` was 1, so the result is 1.

#### Example 2:
Input: arr[] = `[1, 2, 3, 4]`

- Start at index 1 (`arr[1] = 2`), compare with `arr[0] = 1`. Since 2 > 1, increment `current_steps` to 1.
- Move to index 2 (`arr[2] = 3`), compare with `arr[1] = 2`. Since 3 > 2, increment `current_steps` to 2.
- Move to index 3 (`arr[3] = 4`), compare with `arr[2] = 3`. Since 4 > 3, increment `current_steps` to 3.

The maximum consecutive steps is 3, so the result is 3.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
int maxStep(vector<int>& arr) {
    int max_steps = 0;
    int current_steps = 0;
    
    // Loop through the array to find consecutive steps with increasing altitude
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            current_steps++;  // If current building is taller, increment the step count
        } else {
            current_steps = 0;  // Reset if there's no increase in altitude
        }
        max_steps = max(max_steps, current_steps);  // Track the maximum steps
    }
    
    return max_steps;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**:  
  The algorithm traverses the input array once, so the time complexity is `O(n)`, where `n` is the size of the array.

- **Space Complexity**:  
  The algorithm only uses a few extra variables (`max_steps` and `current_steps`), so the space complexity is `O(1)` (constant space).
</details>

<br>

[[back to TOP](#roof-top)]