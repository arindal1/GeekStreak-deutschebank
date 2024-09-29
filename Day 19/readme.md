# Total Count

Difficulty: **Easy** <br>
Tags: **Array**, **Mathematics** <br>
Sokution: **[cpp](totalCount.cpp)** <br>

You are given an array **arr[]** of positive integers and a threshold value **k**. For each element in the array, divide it into the **minimum** number of small integers such that each divided integer is less than or equal to **k**. Compute the total number of these integer across all elements of the array.

**Examples:**

**Input:** k = `3`, arr[] = `[5, 8, 10, 13]` <br>
**Output:** `14` <br>
**Explanation:** Each number can be expressed as sum of different numbers less than or equal to `k` as 5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 13 (3 + 3 + 3 + 3 + 1). So, the sum of count of each element is (2+3+4+5) = 14.

**Input:** k = `4`, arr[] = `[10, 2, 3, 4, 7]` <br>
**Output:** 8 <br>
**Explanation:** Each number can be expressed as sum of different numbers less than or equal to `k` as 10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3). So, the sum of count of each element is (3 + 1 + 1 + 1 + 2) = 8.

**Expected Time Complexity:** `O(n)`  
**Expected Auxiliary Space:** `O(1)`

**Constraints:**  
1 ≤ arr.size() ≤ 10^5  
0 ≤ arr[i] ≤ 10^5  
1 ≤ k ≤ 10^5

## Approach:
The problem requires splitting each element in the array into smaller integers such that each is less than or equal to a given threshold value `k`. The objective is to compute the total count of all such smaller integers across the entire array.

#### Steps:
1. **Iterating over the array**: 
   - For each element `num` in the array `arr[]`, determine how many parts it can be split into, where each part is less than or equal to `k`.
   
2. **Splitting logic**: 
   - If `num` is less than or equal to `k`, it doesn't need splitting and counts as 1 part.
   - If `num` is greater than `k`, it will be divided into multiple parts, each being `≤ k`. To calculate the number of such parts for each `num`, we use:
     - **Mathematical formula**: `ceil(num / k)`, which gives us the smallest integer greater than or equal to `num / k`. To avoid using `ceil` directly, we can use the formula:
       \[
       \text{parts} = \left(\frac{num + k - 1}{k}\right)
       \]
       This effectively divides `num` by `k` and rounds up to the next integer.

3. **Summing the total parts**:
   - For each number, we compute the total number of parts using the formula and accumulate the result.

<br>
<details>
<summary>Example Walkthrough</summary>

Let’s walk through an example:

**Input**: `arr[] = [5, 8, 10, 13]`, `k = 3`.

- **Step 1**: For the number `5`:
  - It needs to be divided into numbers less than or equal to 3.
  - 5 can be split as `3 + 2`.
  - Total parts for 5 = `2` parts.

- **Step 2**: For the number `8`:
  - It can be split as `3 + 3 + 2`.
  - Total parts for 8 = `3` parts.

- **Step 3**: For the number `10`:
  - It can be split as `3 + 3 + 3 + 1`.
  - Total parts for 10 = `4` parts.

- **Step 4**: For the number `13`:
  - It can be split as `3 + 3 + 3 + 3 + 1`.
  - Total parts for 13 = `5` parts.

Total count = `2 + 3 + 4 + 5 = 14`.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
#include <vector>
using namespace std;

int totalCount(int k, vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        // Adding the total number of parts for each element
        total += (num + k - 1) / k;
    }
    return total;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

#### Time Complexity:
- **O(n)** where `n` is the size of the array `arr[]`. 
  - We are iterating over each element of the array once, and for each element, we perform a constant-time arithmetic operation.

#### Space Complexity:
- **O(1)** (Constant space) because we are only using a few integer variables (`total`, `num`, `k`) and not allocating any extra space proportional to the size of the input.
</details>

<br>

[[back to TOP](#total-count)]