# Minimize the Heights I

Difficulty: **Medium** <br>
Tags: **Greedy Algorithm, Array, Min-Max Problem** <br>

Given an array **arr[]** denoting heights of **N** towers and a positive integer **K**, you have to modify the height of each tower either by increasing or decreasing them by **K** only once.  
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.  

**Note:** Assume that height of the tower can be negative.  
A slight modification of the problem can be found [here](readme.md). 

  
**Example 1:**

**Input:** <br>
K = `2`, N = `4` <br>
arr[] = `{1, 5, 8, 10}` <br>
**Output:** `5` <br>
**Explanation:**
The array can be modified as 
`{3, 3, 6, 8}`. The difference between 
the largest and the smallest is `8-3 = 5`.

**Example 2:**

**Input:** <br>
K = `3`, N = `5` <br>
arr[] = `{3, 9, 12, 16, 20}` <br>
**Output:** `11` <br>
**Explanation:**
The array can be modified as
`{6, 12, 9, 13, 17}`. The difference between 
the largest and the smallest is `17-6 = 11`. 

  
**Your Task:**  
You don't need to read input or print anything. Your task is to complete the function **getMinDiff()** which takes the **arr[], n** and **k** as input parameters and returns an integer denoting the minimum difference.

  
**Expected Time Complexity:** `O(NlogN)`  
**Expected Auxiliary Space:** `O(N)`  
  
**Constraints**  
1 ≤ K ≤ 10^4  
1 ≤ N ≤ 10^5  
1 ≤ arr[i] ≤ 10^5


## Aprroach

You have an array of tower heights and an integer `K`. You need to adjust each tower's height by either increasing or decreasing it by `K` exactly once. Your goal is to find the minimum possible difference between the heights of the tallest and shortest towers after all adjustments.


1. **Sorting the Array**:
   - **Purpose**: Sorting helps in easily calculating the minimum and maximum heights after modifications because it arranges the towers in ascending order.
   - **How**: You sort the array using any efficient sorting algorithm (like Timsort used in standard libraries), which takes `O(n log n)` time.

2. **Initial Difference Calculation**:
   - **Purpose**: Before making any changes, calculate the difference between the maximum and minimum heights in the sorted array.
   - **How**: The initial difference is `arr[n-1] - arr[0]` where `arr[n-1]` is the maximum height and `arr[0]` is the minimum height in the sorted array.

3. **Modifying Heights**:
   - **Objective**: For each possible modification, compute the new possible smallest and largest heights, and then find the minimum difference achievable.
   - **How**:
     - Iterate through each height in the sorted array (from index 1 to n-1).
     - For each height, calculate two possible new minimum and maximum heights:
       - **New Minimum Height (`MIN`)**:
         - If you increase the smallest height (`arr[0]`) by \( K \), it becomes `arr[0] + K`.
         - If you decrease the current height (`arr[i]`) by \( K \), it becomes `arr[i] - K`.
         - The potential new minimum height after modifications can be `min(arr[0] + K, arr[i] - K)`.
       - **New Maximum Height (`MAX`)**:
         - If you increase the previous height (`arr[i-1]`) by \( K \), it becomes `arr[i-1] + K`.
         - If you decrease the largest height (`arr[n-1]`) by \( K \), it becomes `arr[n-1] - K`.
         - The potential new maximum height after modifications can be `max(arr[i-1] + K, arr[n-1] - K)`.
     - Calculate the difference between the `MAX` and `MIN` and update the minimum difference (`ans`).

4. **Update Minimum Difference**:
   - **Purpose**: Keep track of the smallest difference found after all possible modifications.
   - **How**: Use `ans = min(ans, MAX - MIN)` to update the minimum difference after considering each modification scenario.
  
 <br>
<details>
<summary>Example Walkthrough</summary>
 <br>
Consider the example:
- **Input**: `arr = [1, 5, 8, 10]` and `K = 2`

1. **Sort the Array**: Already sorted in this case: `[1, 5, 8, 10]`.
2. **Initial Difference**: `10 - 1 = 9`.

3. **Iterate through the Array**:
   - For `i = 1`:
     - `MIN = min(1 + 2, 5 - 2) = min(3, 3) = 3`
     - `MAX = max(1 + 2, 10 - 2) = max(3, 8) = 8`
     - Difference: `8 - 3 = 5`
   - For `i = 2`:
     - `MIN = min(1 + 2, 8 - 2) = min(3, 6) = 3`
     - `MAX = max(5 + 2, 10 - 2) = max(7, 8) = 8`
     - Difference: `8 - 3 = 5`
   - For `i = 3`:
     - `MIN = min(1 + 2, 10 - 2) = min(3, 8) = 3`
     - `MAX = max(8 + 2, 10 - 2) = max(10, 8) = 10`
     - Difference: `10 - 3 = 7`

4. **Final Minimum Difference**: The smallest difference found is `5`.
</details>
 <br>
<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    // Edge case: if there is only one tower, the difference is 0.
    if (n == 1) return 0;
    
    // Sort the array
    sort(arr, arr + n);
    
    // Initialize the minimum difference with the initial max - min
    int ans = arr[n - 1] - arr[0];
    
    // Iterate through the array to find the minimum difference
    for (int i = 1; i < n; i++) {
        // Compute the potential minimum and maximum values after adjusting heights
        int MIN = min(arr[0] + k, arr[i] - k);
        int MAX = max(arr[i - 1] + k, arr[n - 1] - k);
        
        // Update the minimum difference found
        ans = min(ans, MAX - MIN);
    }
    
    return ans;
}

int main() {
    int k = 10;
    int arr[] = {8, 1, 5, 4, 7, 5, 7, 9, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getMinDiff(arr, n, k) << endl;  // Expected output: 7
    return 0;
}
```
</details>
 <br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: `O(n log n)`
- **Space Complexity**: `O(1)` (excluding input storage)
</details>
