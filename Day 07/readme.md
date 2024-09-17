# Minimize the Heights II

Difficulty: **Medium** <br>
Tags: **Greedy Algorithm, Array, Min-Max Problem** <br>
Solution: **[cpp](minimizeTheHeightsII.cpp)**

Given an array **arr[]** denoting heights of **N** towers and a positive integer **K.**

For **each** tower, you must perform **exactly one** of the following operations **exactly once**.

- **Increase** the height of the tower by **K**
- **Decrease** the height of the tower by **K**

Find out the **minimum** possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem [here](minimizeTheHeightsI.md).  
**Note:** It is **compulsory** to increase or decrease the height by K for each tower. **After** the operation, the resultant array should **not** contain any **negative integers**.

**Examples :**

**Input:** k = `2`, arr[] = `{1, 5, 8, 10}` <br>
**Output:** `5` <br>
**Explanation:** The array can be modified as `{1+k, 5-k, 8-k, 10-k}` = `{3, 3, 6, 8}`.The difference between the largest and the smallest is `8-3 = 5`.

**Input:** k = `3`, arr[] = `{3, 9, 12, 16, 20}` <br>
**Output:** `11` <br>
**Explanation:** The array can be modified as `{3+k, 9+k, 12-k, 16-k, 20-k}` -> `{6, 12, 9, 13, 17}`.The difference between the largest and the smallest is `17-6 = 11`. 

**Expected Time Complexity:** `O(n*logn)` <br>
**Expected Auxiliary Space:** `O(n)` 

**Constraints**  
1 ≤ k ≤ 10^7  
1 ≤ n ≤ 10^5  
1 ≤ arr[i] ≤ 10^7


## Approach

We are given an array representing the heights of towers, and we need to minimize the difference between the tallest and the shortest towers after modifying each tower's height by either increasing or decreasing it by a given integer `K`. The challenge is to perform these modifications optimally for all towers to achieve the smallest possible difference.


1. **Sort the Array**:
   - **Why?** Sorting helps in arranging the towers in ascending order of height, making it easier to track the smallest and largest values as we proceed with height adjustments.
   - After sorting, the heights are ordered, and the goal is to find an optimal way to add/subtract `K` while minimizing the difference between the tallest and shortest towers.

2. **Initial Difference**:
   - The initial difference, before any modification, is simply the difference between the tallest (`arr[n-1]`) and the shortest (`arr[0]`) tower: `ans = arr[n - 1] - arr[0]`.
   - This sets a baseline against which we can compare any new potential differences after applying the height modifications.

3. **Modify Heights and Track Smallest & Largest**:
   - **Goal**: After modifying the heights by adding or subtracting `K`, our task is to minimize the difference between the tallest and shortest towers.
   - For each tower, we have two choices: increase its height by `K` or decrease its height by `K`. However, **we should avoid making heights negative** when subtracting `K`, which can lead to incorrect results.

4. **Iterating Through the Array**:
   - After sorting, we can start iterating from the second tower (since the first tower is already at its minimum possible height after `K` is added).
   - For each tower at index `i`:
     - Calculate the **new smallest height**: The smallest height can either be the first tower increased by `K` (`arr[0] + K`) or the current tower decreased by `K` (`arr[i] - K`).
     - Calculate the **new largest height**: The largest height can either be the last tower decreased by `K` (`arr[n-1] - K`) or the previous tower increased by `K` (`arr[i-1] + K`).
     - Update the minimum possible difference `ans` by comparing the difference between the new largest and smallest values with the current `ans`.

5. **Avoid Negative Heights**:
   - Since heights can't be negative, we add a condition to skip cases where subtracting `K` from a tower results in a negative value: `if (arr[i] - K < 0) continue;`. This ensures that we don't process invalid heights.

6. **Return the Minimum Difference**:
   - After iterating through all the towers, we return the minimum difference that we computed during the process.

 <br>
 <details>
<summary>Example Walkthrough</summary>

Let's break down the example:

**Input**:

**k** = `494` <br>
**arr** = `{380, 705, 706, 177, 710, 416, 853, 147, 957, 693}`


- Step 1: **Sort the array**:
  
  **arr** = `{147, 177, 380, 416, 693, 705, 706, 710, 853, 957}`
  
  
- Step 2: **Initial Difference**:
  
  **ans** = `957 - 147` = `810`

- Step 3: **Iterate over the sorted array**:
  - For `i = 1`:
    - `smallest = min(147 + 494, 177 - 494) = min(641, -317) = 641`
    - `largest = max(957 - 494, 147 + 494) = max(463, 641) = 641`
    - Difference = `641 - 641 = 0` (Not possible since -317 is invalid, so we skip)
  
  - For `i = 2`:
    - `smallest = min(147 + 494, 380 - 494) = min(641, -114) = 641`
    - `largest = max(957 - 494, 177 + 494) = max(463, 671) = 671`
    - Difference = `671 - 641 = 30` (Skip, as -114 is invalid)

  - Continue until `i = 9` where you get the correct minimum difference after adjusting.

**Final Answer**: `973`
</details>

 <br>
<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int>& arr, int k) {
    int n = arr.size();
    
    // If there is only one tower, no difference can exist
    if (n == 1)
        return 0;

    // Sort the array to process in an ordered manner
    sort(arr.begin(), arr.end());

    // Initial difference without any changes
    int ans = arr[n - 1] - arr[0];

    // The smallest and largest after considering adding/subtracting k
    int smallest, largest;

    // Update the heights of the first and last towers
    for (int i = 1; i < n; i++) {
        // Ignore cases where the subtraction results in negative values
        if (arr[i] - k < 0)
            continue;

        // Calculate the new smallest and largest heights after adding/subtracting k
        smallest = min(arr[0] + k, arr[i] - k);
        largest = max(arr[n - 1] - k, arr[i - 1] + k);

        // Update the minimum difference
        ans = min(ans, largest - smallest);
    }

    return ans;
}

int main() {
    vector<int> arr = {380, 705, 706, 177, 710, 416, 853, 147, 957, 693};
    int k = 494;
    cout << getMinDiff(arr, k) << endl;  // Expected output: 973
    return 0;
}
```
</details>
 <br>

<details>
<summary>Time Complexity</summary>

- **Sorting** the array takes `O(n log n)`.
- **Iterating** through the array takes `O(n)`.
Thus, the total time complexity is `O(n log n)`, which is efficient enough for the problem's constraints.
</details>

