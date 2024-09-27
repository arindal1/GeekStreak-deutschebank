# K Sized Subarray Maximum

Difficulty: **Medium** <br>
Tags: **Sliding Window**, **Deque**, **Array** <br>
Solution: **[cpp](kSizedSubarray.cpp)** <br>

Given an array **arr**[] and an integer **k**. Find the **maximum** for each and every contiguous subarray of size **k**.

**Examples:**

**Input:** k = `3`, arr[] = `[1, 2, 3, 1, 4, 5, 2, 3, 6]` <br>
**Output:** `[3, 3, 4, 5, 5, 5, 6]`  <br>
**Explanation:**  <br>
1st contiguous subarray = [1 2 3] max = 3 <br>
2nd contiguous subarray = [2 3 1] max = 3 <br>
3rd contiguous subarray = [3 1 4] max = 4 <br>
4th contiguous subarray = [1 4 5] max = 5 <br>
5th contiguous subarray = [4 5 2] max = 5 <br>
6th contiguous subarray = [5 2 3] max = 5 <br>
7th contiguous subarray = [2 3 6] max = 6  
  

**Input:** k = `4`, arr[] = `[8, 5, 10, 7, 9, 4, 15, 12, 90, 13]` <br>
**Output:** `[10, 10, 10, 15, 15, 90, 90]` <br>
**Explanation:**  <br>
1st contiguous subarray = [8 5 10 7], max = 10 <br>
2nd contiguous subarray = [5 10 7 9], max = 10 <br>
3rd contiguous subarray = [10 7 9 4], max = 10 <br>
4th contiguous subarray = [7 9 4 15], max = 15 <br>
5th contiguous subarray = [9 4 15 12], max = 15 <br>
6th contiguous subarray = [4 15 12 90], max = 90 <br>
7th contiguous subarray = {15 12 90 13}, max = 90

**Expected Time Complexity:** `O(n)`  
**Expected Auxiliary Space:** `O(k)`

**Constraints:**  
1 ≤ sizeof(arr) ≤ 10^6  
1 ≤ k ≤ sizeof(arr)  
0 ≤ arr[i] ≤ 10^9

## Approach

The problem requires finding the maximum element for every contiguous subarray of size `k`. This can be solved efficiently using a **deque (double-ended queue)**, which helps keep track of the indices of array elements in a way that allows both insertion and removal of elements from both ends in constant time, thus maintaining the maximum element at the front.

Here’s the breakdown of the approach:

1. **Sliding Window using Deque:**
   - Maintain a deque to store indices of array elements, where the front of the deque holds the index of the maximum element for the current window.
   - As you slide the window (from left to right in the array), for each new element:
     - Remove elements from the front of the deque that are out of the window’s bounds.
     - Remove elements from the back of the deque that are smaller than the current element since they will no longer be useful (the current element will dominate them in future windows).
   - After processing the first `k` elements, the front of the deque will always hold the index of the maximum element for the current window.

2. **Add the maximum element to the result:**
   - After processing each window, add the element at the index stored in the front of the deque to the result array.

<br>
<details>
<summary>Example Walkthrough</summary>

Let's walk through the example `arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]` with `k = 3`.

1. **Window [1, 2, 3]:**
   - Insert 1 (index 0) → `deque = [0]`
   - Insert 2 (index 1), pop 1 (index 0) since 2 > 1 → `deque = [1]`
   - Insert 3 (index 2), pop 2 (index 1) since 3 > 2 → `deque = [2]`
   - The max of this window is `arr[2] = 3`.

2. **Window [2, 3, 1]:**
   - Move the window. Remove index 2 as it is within the window and still the largest → `deque = [2]`
   - Insert 1 (index 3), no pops required since 3 > 1 → `deque = [2, 3]`
   - The max of this window is `arr[2] = 3`.

3. **Window [3, 1, 4]:**
   - Move the window. Pop index 2 (3 is out of the current window) → `deque = [3]`
   - Insert 4 (index 4), pop 1 (index 3) → `deque = [4]`
   - The max of this window is `arr[4] = 4`.

4. Continue this process until the end of the array.

Final result: `[3, 3, 4, 5, 5, 5, 6]`.

</details>

<br>
<details>
<summary>Code</summary>


```cpp
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> max_of_subarrays(int k, vector<int> &arr) {
    vector<int> result;
    deque<int> dq;
    
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        
        // Add the current element's index to the deque
        dq.push_back(i);
        
        // If we have processed at least 'k' elements, add the front of the deque to the result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> result = max_of_subarrays(k, arr);
    
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

1. **Time Complexity:**
   - Each element is pushed to and popped from the deque at most once, so the operations involving the deque take linear time.
   - Time complexity: `O(n)`, where `n` is the size of the array.

2. **Space Complexity:**
   - The deque stores at most `k` elements at a time.
   - Result array takes `O(n)` space.
   - Space complexity: `O(k)` for the deque, and `O(n)` for the result array.

</details>

<br>

[[back to TOP](#k-sized-subarray-maximum)]

