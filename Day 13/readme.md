# Missing And Repeating

Difficulty: **Medium** <br>
Tags: **Array**, **Cyclic Sort** <br>
Solution: **[cpp](missingAndRepeating.cpp)**

Given an unsorted array **_arr_** of of positive integers. One number '**A**' from set {1, 2,....,n} is missing and one number '**B**' occurs twice in array. Find numbers **A** and **B**.  

**Examples:**  

**Input:** arr[] = `[2, 2]` <br>
**Output:** `2 1` <br>
**Explanation:** **Repeating** number is `2` and **smallest** positive missing number is `1`.

**Input:** arr[] = `[1, 3, 3]` <br>
**Output:** `3 2` <br>
**Explanation:** Repeating number is `3` and **smallest** positive **missing** number is `2`.

**Expected Time Complexity:** `O(n)`  
**Expected Auxiliary Space:** `O(1)`

**Constraints:**  
2 ≤ n ≤ 10^5  
1 ≤ arr[i] ≤ n


## Approach

The algorithm used here involves **marking and detection** via **index negation**. This approach allows us to identify the repeating and missing numbers efficiently in a single traversal of the array.

#### Steps:
1. **Mark Visited Elements (Index Negation):**
   - As we traverse the array, for each element `arr[i]`, we check the index `index = abs(arr[i]) - 1`.
   - If the value at that index is positive, we mark it visited by negating it (i.e., `arr[index] = -arr[index]`).
   - If we encounter a negative value at that index, it means that the current element has already been seen, so it is the repeating number.
   
2. **Identify the Missing Element:**
   - After marking all visited elements, we traverse the array again.
   - The index that remains positive indicates the missing number, as its corresponding value wasn't encountered in the array.

<br>
<details>
<summary>Example Walkthrough</summary>

#### Input:
arr[] = `[1, 3, 3]`

#### Step 1: Mark visited elements
- Start with the first element:
  - `arr[0] = 1` → check index `abs(1) - 1 = 0`. Mark index 0 as visited: `arr[0] = -arr[0]`.
  - Array becomes: `[-1, 3, 3]`.
  
- Move to the second element:
  - `arr[1] = 3` → check index `abs(3) - 1 = 2`. Mark index 2 as visited: `arr[2] = -arr[2]`.
  - Array becomes: `[-1, 3, -3]`.
  
- Move to the third element:
  - `arr[2] = -3` → check index `abs(3) - 1 = 2`. Since index 2 is already negative, we found the repeating number, `B = 3`.

#### Step 2: Identify the missing element
- Traverse the array to find which index is still positive:
  - `arr[0]` is negative.
  - `arr[1]` is positive → hence, the missing number is `A = 2`.

#### Output: 
The repeating number is `3`, and the missing number is `2`. The result is `[3, 2]`.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int repeating = 0, missing = 0;
    
    // Step 1: Traverse the array and mark visited elements by negating
    for (int i = 0; i < n; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) {
            repeating = abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }
    
    // Step 2: Find the missing element
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            missing = i + 1;
        }
    }
    
    return {repeating, missing};
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity:** `O(n)`
  - We traverse the array twice — once to mark visited elements and once to find the missing number.
  
- **Space Complexity:** `O(1)`
  - We do not use any extra space beyond the input array itself, making it constant auxiliary space.
</details>

<br>
<details>
<summary>Alternative Approach</summary>


Another approach that can also achieve `O(n)` time and `O(1)` space involves using **mathematical properties**:
1. **Sum Formula (S)**: The sum of numbers from `1` to `n` is `S = n * (n + 1) / 2`.
2. **Sum of Squares (Ssq)**: The sum of squares of numbers from `1` to `n` is `Ssq = n * (n + 1) * (2n + 1) / 6`.

Using these formulas, we calculate:
- The actual sum (`actual_sum`) and sum of squares (`actual_sum_sq`) of the elements in the array.
- The difference between `S` and `actual_sum` gives us `missing - repeating`.
- The difference between `Ssq` and `actual_sum_sq` gives us `missing^2 - repeating^2`.

We can solve these two equations to find the missing and repeating numbers.

#### Time and Space Complexity of this approach:
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
</details>


<br>

[[back to TOP](#missing-and-repeating)]