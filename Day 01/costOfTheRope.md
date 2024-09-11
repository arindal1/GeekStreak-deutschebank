# Minimum Cost of Ropes

**Difficulty:** Easy

**Problem Statement:** Given an array **arr** containing the lengths of the different ropes, we need to connect these ropes to form one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

**Example 1:** <br>
**Input:** arr[] = [4, 3, 2, 6] <br>
**Output:** 29 <br>
**Explanation:** <br>
We can connect the ropes in following ways:
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15
4) Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 

Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we gettwo rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

**Example 2:** <br>
**Input:** arr[] = [4, 2, 7, 6, 9] <br>
**Output:** 62 <br>
**Explanation:** <br>
First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6.  
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.

**Expected Time Complexity**: O(n logn)  
**Expected Auxilliary Space**: O(n)

**Constraints:**  
1 ≤ arr.size() ≤ 20^5  
1 ≤ arr[i] ≤ 10^6


<br>

## Approach

To minimize the total cost, we should always connect the two smallest ropes first. This is because adding larger ropes earlier would result in a higher cost for subsequent operations. By consistently connecting the smallest ropes first, we keep the intermediate sums low.

#### Min-Heap (Priority Queue):

A min-heap is a data structure that allows us to efficiently get the smallest element. In this case, we need to repeatedly find and remove the two smallest ropes.
We first insert all the ropes into a min-heap. This ensures that every time we extract elements, we get the smallest ones.
Greedy Strategy:

The strategy is to always take the two smallest ropes, combine them, and then put the result back into the heap. This is a greedy algorithm because at each step, we make the local optimal choice (connect the two smallest ropes) in hopes of achieving a globally optimal solution (minimize the total cost).

#### Steps in the Algorithm:

1. Insert all ropes into the heap. This takes O(n) time since heapifying an array can be done in linear time.
2. While there is more than one rope in the heap:
3. Extract the two smallest ropes (this takes O(log n) time for each extraction).
4. Add the sum of these two ropes to the total cost.
5. Insert the combined rope back into the heap (insertion takes O(log n) time).
6. Continue this process until only one rope remains in the heap.


```cpp
class Solution {
  public:
    long long minCost(std::vector<long long>& arr) {
        // Convert the input array into a min-heap (priority queue).
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq(std::move(arr));
        
        long long totalCost = 0;
        
        // While more than one rope remains.
        while (pq.size() > 1) {
            // Take the two smallest ropes.
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            // Combine them and calculate the cost.
            long long cost = first + second;
            totalCost += cost;
            
            // Add the new rope to the heap.
            pq.push(cost);
        }
        
        return totalCost;
    }
};
```

**Time complexity:** `O(n log n)` (optimal for this type of problem). <br>
**Space complexity:** `O(n)` due to the priority queue and the initial array.