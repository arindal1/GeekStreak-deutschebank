# Facing the sun

Difficulty: **Easy** <br>
Tags: **Greedy**, **Array** <br>
Solution: **[cpp](facingTheSun.cpp)** <br>

Given an array **height** representing the heights of buildings. You have to count the buildings that will see the sunrise (Assume the sun rises on the side of the array starting point).  
_Note:_ The height of the building should be strictly greater than the height of the buildings left in order to see the sun.  
![](https://contribute.geeksforgeeks.org/wp-content/uploads/Building.png)

**Examples :**

**Input:** height = `[7, 4, 8, 2, 9]` <br>
**Output:** `3` <br>
**Explanation:** As 7 is the first element, it can see the sunrise. 4 can't see the sunrise as 7 is hiding it. 8 can see. 2 can't see the sunrise. 9 also can see  
the sunrise.

**Input:** height = `[2, 3, 4, 5]` <br>
**Output:** `4` <br>
**Explanation:** As 2 is the first element, it can see the sunrise.  3 can see the sunrise as 2 is not hiding it. Same for 4 and 5, they also can see the sunrise.

**Expected Time Complexity:** `O(n)` <br>
**Expected Auxiliary Space:** `O(1)` <br>

**Constraints:**  
1 ≤ height.size() ≤ 10^6  
1 ≤ height ≤ 10^8

## Approach

The approach follows a greedy method to solve the problem in **O(n)** time, while using **O(1)** extra space.

1. **Initialize Count**:
   We start by counting the first building because it can always see the sunrise (no buildings to block its view). Hence, we initialize the `count` to 1.

2. **Track Maximum Height Seen So Far**:
   We need to keep track of the maximum height of buildings that have already been processed (from left to right). This helps determine whether the current building can see the sunrise or not.
   - We initialize `max_height` as the height of the first building (`height[0]`).

3. **Iterate Through the Array**:
   Starting from the second building (i.e., index 1), we process each building one by one:
   
   - **Condition**: For a building to see the sunrise, its height must be greater than the maximum height of any building to its left.
   
   - If the current building's height is greater than `max_height` (i.e., no previous building is taller than it), this building can see the sunrise.
     - We increment the `count` by 1.
     - We update `max_height` to the current building's height, as this is now the tallest building encountered so far.

4. **Continue Until All Buildings Are Processed**:
   We repeat this process for every building in the array until we reach the last one.

5. **Return the Count**:
   Once we finish processing all the buildings, the `count` will hold the total number of buildings that can see the sunrise.



<br>
<details>
<summary>Example Walkthrough</summary>

For the input:

**height** = `[7, 4, 8, 2, 9]`

- The first building (`7`) can always see the sunrise. So, `count = 1` and `max_height = 7`.
- The second building (`4`) is shorter than `7`, so it can't see the sunrise.
- The third building (`8`) is taller than `7` (the tallest so far), so it can see the sunrise. Now, `count = 2` and `max_height = 8`.
- The fourth building (`2`) is shorter than `8`, so it can't see the sunrise.
- The fifth building (`9`) is taller than `8` (the tallest so far), so it can see the sunrise. Now, `count = 3`.

Thus, the total number of buildings that can see the sunrise is `3`.

</details>

<br>
<details>
<summary>Code</summary>

```cpp
int countBuildings(vector<int> &height) {
    int count = 1; // The first building can always see the sunrise
    int max_height = height[0]; // The first building's height
    
    // Traverse the array from the second building onwards
    for(int i = 1; i < height.size(); i++) {
        if(height[i] > max_height) {
            count++; // This building can see the sunrise
            max_height = height[i]; // Update the maximum height seen so far
        }
    }
    
    return count;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- `O(n)`: We traverse the array once, processing each building in constant time.
- `O(1)`: We use only a few extra variables (`count` and `max_height`), regardless of the input size.
</details>