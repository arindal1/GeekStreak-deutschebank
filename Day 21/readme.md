# Multiply two Linked Lists

Difficulty: **Easy** <br>
Tags: **Linked List**, **Recursion**, **Stack** <br>
Solution: **[cpp](multiplyLinkedList.cpp)**

Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

*Note:* The output could be large take modulo 10^9+7.

**Examples :**

**Input:** LinkedList **L1** : `3->2` , LinkedList **L2** : `2`  
**Output:** `64` <br>
**Explanation:   
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700336/Web/Other/blobid0_1721108424.png)**  <br>
Multiplication of 32 and 2 gives 64.

**Input:** LinkedList **L1**: `1->0->0` , LinkedList **L2** : `1->0 `  <br>
**Output:** `1000` <br>
**Explanation:   
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700336/Web/Other/blobid1_1721108436.png)**  <br>
Multiplication of 100 and 10 gives 1000.

**Expected Time Complexity**: `O(max(n,m))` <br> 
**Expected Auxilliary Space**: `O(1)` <br>
[where **n** is the size of **L1** and **m** is the size of **L2**]

**Constraints:**  
1 <= number of nodes <= 10^5   <br>
1 <= node->data <= 10^3 <br>

## Approach

The approach revolves around representing each linked list as a number, multiplying these numbers, and then returning the result modulo \( 10^9 + 7 \) to avoid overflow. Here are the detailed steps:

1. **Convert Linked Lists to Numbers**: 
   Each node of the linked list contains a digit. By traversing the linked list, we can construct the number by starting from the head node. Multiply the current number by 10 and add the node’s value to shift the number to the left, effectively constructing the number in a base-10 system.

   - For example, a linked list `3 -> 2` becomes the number `32`.

2. **Multiply the Two Numbers**:
   After converting both linked lists into their corresponding numbers, we multiply them and take the result modulo \( 10^9 + 7 \).

3. **Modulo Operation**:
   Since the result could be very large, we continuously perform modulo \( 10^9 + 7 \) during the number construction and the final multiplication to ensure the result fits within the bounds of typical integer types.

<br>
<details>
<summary>Example Walkthrough</summary>

Consider two linked lists:

- Linked List 1 (`L1`): `3 -> 2`
- Linked List 2 (`L2`): `2`

1. **Convert `L1` (3 -> 2) into a number**:
   - Start with `num1 = 0`.
   - First node value is `3`:  
     `num1 = (0 * 10 + 3) % (10^9 + 7) = 3`.
   - Second node value is `2`:  
     `num1 = (3 * 10 + 2) % (10^9 + 7) = 32`.

   So, `L1` represents the number `32`.

2. **Convert `L2` (2) into a number**:
   - Start with `num2 = 0`.
   - First node value is `2`:  
     `num2 = (0 * 10 + 2) % (10^9 + 7) = 2`.

   So, `L2` represents the number `2`.

3. **Multiply the numbers**:
   Multiply `num1` and `num2`:  
   `result = (32 * 2) % (10^9 + 7) = 64`.

   Hence, the result of multiplying the two linked lists is `64`.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to multiply two linked lists
long long multiplyTwoLists(Node* first, Node* second) {
    long long num1 = 0, num2 = 0;
    
    while (first) {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }
    
    while (second) {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }
    
    return (num1 * num2) % MOD;
}

// Driver code
int main() {
    Node* L1 = new Node(3);
    L1->next = new Node(2);
    
    Node* L2 = new Node(2);
    
    cout << multiplyTwoLists(L1, L2) << endl; // Output: 64
    
    return 0;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**:
  - Converting a linked list into a number takes `O(n)` time where `n` is the number of nodes in the first linked list.
  - Converting the second linked list takes `O(m)` time where `m` is the number of nodes in the second linked list.
  - Thus, the overall time complexity is `O(n + m)`, which simplifies to `O(max(n, m))`.

- **Space Complexity**:
  - The space complexity is `O(1)` since we only use a few extra variables (`num1`, `num2`) and do not use additional space for recursion or arrays.

</details>
