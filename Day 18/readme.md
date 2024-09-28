# Minimal Cost

Difficulty: **Medium** <br>
Tags: **Greedy Algorithm**, **Dynamic Programming**. **Arrays** <br>
Solution: **[cpp](minimalCost.cpp)** <br>

There is an array **arr** of heights of stone and Geek is standing at the first stone and can jump to one of the following:  <br>
Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

**Example:**

**Input:** k = `3`, arr[]= `[10, 30, 40, 50, 20]`   <br>
**Output:** `30`   <br>
**Explanation:** Geek will follow the path `1->2->5`, the total cost would be `|10-30| + |30-20| = 30`, which is minimum

**Input:** k = `1`, arr[]= `[10, 20, 10]` <br>
**Output:** `20` <br>
**Explanation:** Geek will follow the path `1->2->3`, the total cost would be `|10 - 20| + |20 - 10| = 20`.

**Expected Time Complexity**: `O(n*k)`  
**Expected Auxilary Space**: `O(n)`

**Constraint**:  
1<= arr.size() <=10^4   <br>
1 <= k <= 100  <br>
1 <= arr[i] <= 10^4 <br>

---

## **Approach**

This problem can be solved using **Dynamic Programming (DP)**, which is an optimization technique where we store the results of overlapping subproblems to avoid redundant calculations.

- We define a `dp[]` array where `dp[i]` represents the minimum cost to reach stone `i`.
- Starting from the first stone (`dp[0] = 0`), we compute the minimum cost to reach each subsequent stone.
- To calculate `dp[i]`, we look at the previous `k` stones from which the Geek could have jumped (i.e., stones `i-1, i-2, ..., i-k`).
- The transition relation is:

        dp[i] = min(dp[i], dp[i - j] + |arr[i] - arr[i - j]|)

  where `1 <= j <= k` and `i - j >= 0`. This relation means that for each stone `i`, we check all possible previous stones within the jump range `k` and update `dp[i]` with the minimum cost incurred.

<br>
<details>
<summary>Example Walkthrough</summary>

Let's take the example:

**Input**: `k = 3`, `arr[] = [10, 30, 40, 50, 20]`

- Initialize the DP array: `dp[] = [0, INF, INF, INF, INF]`
  (where `INF` is a large value like `INT_MAX` used to represent an initially unreachable stone)

- **Stone 1 (`i = 0`)**: No cost as we start here, so `dp[0] = 0`.

- **Stone 2 (`i = 1`)**: 
  - We can jump from `dp[0]` to `dp[1]`.
  - `dp[1] = min(INF, dp[0] + |arr[1] - arr[0]|) = min(INF, 0 + |30 - 10|) = 20`.
  - So, `dp[1] = 20`.

- **Stone 3 (`i = 2`)**:
  - We can jump from either stone `dp[1]` or `dp[0]`:
    - From `dp[1]`: `dp[2] = min(INF, dp[1] + |arr[2] - arr[1]|) = min(INF, 20 + |40 - 30|) = 30`
    - From `dp[0]`: `dp[2] = min(30, dp[0] + |arr[2] - arr[0]|) = min(30, 0 + |40 - 10|) = 30`
  - So, `dp[2] = 30`.

- **Stone 4 (`i = 3`)**:
  - We can jump from `dp[2]`, `dp[1]`, or `dp[0]`:
    - From `dp[2]`: `dp[3] = min(INF, dp[2] + |arr[3] - arr[2]|) = min(INF, 30 + |50 - 40|) = 40`
    - From `dp[1]`: `dp[3] = min(40, dp[1] + |arr[3] - arr[1]|) = min(40, 20 + |50 - 30|) = 40`
    - From `dp[0]`: `dp[3] = min(40, dp[0] + |arr[3] - arr[0]|) = min(40, 0 + |50 - 10|) = 40`
  - So, `dp[3] = 40`.

- **Stone 5 (`i = 4`)**:
  - We can jump from `dp[3]`, `dp[2]`, or `dp[1]`:
    - From `dp[3]`: `dp[4] = min(INF, dp[3] + |arr[4] - arr[3]|) = min(INF, 40 + |20 - 50|) = 70`
    - From `dp[2]`: `dp[4] = min(70, dp[2] + |arr[4] - arr[2]|) = min(70, 30 + |20 - 40|) = 50`
    - From `dp[1]`: `dp[4] = min(50, dp[1] + |arr[4] - arr[1]|) = min(50, 20 + |20 - 30|) = 30`
  - So, `dp[4] = 30`.

**Result**: The minimum cost to reach the last stone is `dp[4] = 30`.
</details>

<br>
<details>
<summary>Code</summary>


```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX); // DP array to store the minimum cost
    dp[0] = 0; // Cost of starting at the first stone is 0

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
            }
        }
    }
    return dp[n - 1]; // Minimum cost to reach the last stone
}

int main() {
    vector<int> arr = {10, 30, 40, 50, 20};
    int k = 3;
    cout << minimizeCost(k, arr) << endl; // Output: 30
    return 0;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: `O(n * k)`
  - For each stone `i`, we look back at up to `k` previous stones, which gives us a time complexity of `O(k)` for each stone.
  - Since there are `n` stones, the total time complexity is `O(n * k)`.

- **Space Complexity**: `O(n)`
  - We use an auxiliary `dp[]` array of size `n` to store the minimum cost to reach each stone.
</details>


<br>

[[back to TOP](#minimal-cost)]