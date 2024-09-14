# Alternate Positive and Negetive Numbers

**DIfficulty:** Easy <br>
**Tags:** Arrays, Two Pointers <br>
**Solution:** [cpp](alternatePositiveAndNegative.cpp) <br>

Given an unsorted array **arr** containing both **positive** and **negative** numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.  
**Note:** Array should start with a positive number and 0 (zero) should be considered a positive element.

**Examples:**

**Input:** arr[] = `[9, 4, -2, -1, 5, 0, -5, -3, 2]` <br>
**Output:** `9 -2 4 -1 5 -5 0 -3 2` <br>

**Explanation:** <br>
Positive elements : `[9,4,5,0,2]` <br>
Negative elements : `[-2,-1,-5,-3]` <br>
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.  <br> 
The output is `9,-2,4,-1,5,-5,0,-3,2`.

**Input:** arr[] = `[-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]` <br>
**Output:** `5 -5 2 -2 4 -8 7 1 8 0` <br>
**Explanation :** <br>
Positive elements : `[5,2,4,7,1,8,0]` <br>
Negative elements : `[-5,-2,-8]` <br>
The output is `5, -5, 2, -2, 4, -8, 7, 1, 8, 0`.

**Expected Time Complexity:** `O(n)`  
**Expected Auxiliary Space:** `O(n)`

**Constraints:**  
1 ≤ arr.size() ≤ 10^7  
-10^6 ≤ arr[i] ≤ 10^7


## Approach

1. **Splitting the Array:**
   We first need to separate the positive and negative numbers from the given array while maintaining their relative order. We will store these numbers in two separate arrays:
   - `positive`: Stores all non-negative numbers (positive numbers and 0).
   - `negative`: Stores all negative numbers.

2. **Rearranging with Alternation:**
   After separating the numbers, we will start rearranging the original array by alternating between a positive number and a negative number.
   - The first number in the array should be positive.
   - After placing a positive number, the next number should be negative, and so on.

3. **Handling Extra Numbers:**
   If one of the lists (positive or negative) runs out of elements before the other, the remaining elements of the other list will be appended at the end of the array.

### Steps of the Algorithm:

#### 1. Splitting the array into positive and negative numbers:
   - We loop through the original array and separate the elements into two lists:
     - Positive list `positive` contains all non-negative numbers.
     - Negative list `negative` contains all negative numbers.

#### 2. Rebuilding the array:
   - We initialize two indices, `posIndex` and `negIndex`, to keep track of the current position in the positive and negative lists respectively.
   - We loop through the original array and place the elements alternately:
     - If the index is even (0, 2, 4, ...), we place a positive number.
     - If the index is odd (1, 3, 5, ...), we place a negative number.
   - We increment the `posIndex` or `negIndex` accordingly as we use the elements from the respective lists.

#### 3. Filling the remaining elements:
   - If all the elements from one list (positive or negative) have been used but there are still remaining elements in the other list, we simply append them to the end of the array.

### Example Walkthrough:

For the input array `arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]`, let’s walk through the process:

1. **Separating Positive and Negative Elements:**
   - Positive elements: `[9, 4, 5, 0, 2]`
   - Negative elements: `[-2, -1, -5, -3]`

2. **Rebuilding the Array with Alternating Elements:**
   - Start with a positive element (`9`), then a negative element (`-2`):
     - Array so far: `[9, -2]`
   - Next, positive (`4`), then negative (`-1`):
     - Array so far: `[9, -2, 4, -1]`
   - Continue alternating:
     - `[9, -2, 4, -1, 5, -5]`
     - `[9, -2, 4, -1, 5, -5, 0, -3]`
   - Finally, place the remaining positive number (`2`):
     - Final array: `[9, -2, 4, -1, 5, -5, 0, -3, 2]`


```cpp
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positive, negative;
        
        for (int num : arr) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }
    
        int posIndex = 0, negIndex = 0, i = 0;
        while (posIndex < positive.size() && negIndex < negative.size()) {
            if (i % 2 == 0) {
                arr[i] = positive[posIndex++];
            } else {
                arr[i] = negative[negIndex++];
            }
            i++;
        }
    
        while (posIndex < positive.size()) {
            arr[i++] = positive[posIndex++];
        }
    
        while (negIndex < negative.size()) {
            arr[i++] = negative[negIndex++];
        }
    }
};
```

### Time Complexity:
- **Splitting the array:** We traverse the array once to separate the positive and negative numbers, which takes O(n) time.
- **Rearranging the array:** We traverse the array again to place the numbers alternately, which also takes O(n) time.
- Overall, the time complexity is **O(n)**, where `n` is the number of elements in the array.

### Space Complexity:
- We use additional space to store the `positive` and `negative` lists, each of size at most `n` (the size of the input array).
- So, the auxiliary space complexity is **O(n)**.
