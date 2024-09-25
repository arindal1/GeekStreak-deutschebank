# Palindrome Linked List

Difficulty: **Medium** <br>
Tags: **Linked List**, **Two Pointers** <br>
Solution: **[cpp](palindromeLinkedList.cpp)**

Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

**Examples:**

**Input:** LinkedList: `1->2->1->1->2->1` <br>
**Output:** `true` <br>
**Explanation:** The given linked list is `1->2->1->1->2->1`, which is a palindrome and hence, the output is `true`. 

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700391/Web/Other/blobid0_1722089787.png)

**Input:** LinkedList: `1->2->3->4` <br>
**Output:** `false` <br>
**Explanation:** The given linked list is `1->2->3->4`, which is not a palindrome and hence, the output is `false`.  

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700391/Web/Other/blobid1_1722089845.png)  

**Expected Time Complexity**: `O(n)`  
**Expected Auxiliary Space**: `O(1)`   
Note: You should not use the recursive stack space as well

**Constraints:**  
1 <= number of nodes <= 10^5  
1 ≤ node->data ≤ 10^3

# **Approach**

To check if a singly linked list is a palindrome, we need to determine whether the elements in the first half of the list mirror the elements in the second half in reverse order. Here's how the algorithm works:

1. **Find the Middle of the Linked List**:
   - Use two pointers: `slow` and `fast`. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time.
   - By the time the `fast` pointer reaches the end, the `slow` pointer will be at the middle of the list.

2. **Reverse the Second Half**:
   - Starting from the `slow` pointer (which is at the middle), reverse the second half of the linked list. This ensures that we can compare the first half of the list with the reversed second half.

3. **Compare Both Halves**:
   - Compare the values in the first half and the reversed second half. If all values match, the list is a palindrome.

4. **Restore the List (Optional)**:
   - After the comparison, you can reverse the second half back to its original form to restore the list, if needed.

<br>
<details>
<summary>Example Walkthrough</summary>

Let's consider an example:
```
Input: 1 -> 2 -> 3 -> 2 -> 1
```

1. **Finding the Middle**:
   - Use two pointers (`slow` and `fast`):
     - Initially, both are at the head: `slow = 1`, `fast = 1`.
     - Move `slow` one step and `fast` two steps.
     - `slow = 2`, `fast = 3`.
     - Continue moving: `slow = 3`, `fast = 1` (end of the list).
     - `slow` is now pointing to the middle of the list at node with value `3`.

2. **Reversing the Second Half**:
   - Reverse the second half starting from the node after `slow` (`2 -> 1` becomes `1 -> 2`).

3. **Comparing Both Halves**:
   - Compare the first half (`1 -> 2 -> 3`) with the reversed second half (`1 -> 2`).
   - They match, so the list is a palindrome.

4. **Result**:
   - The function returns `true`.
</details>

<br>
<details>
<summary>Code</summary>


```cpp
class Solution {
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;  // If list is empty or has only one node, it's a palindrome.

        // Step 1: Find the middle of the linked list
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        Node *prev = nullptr, *next = nullptr, *curr = slow;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare both halves
        Node *firstHalf = head, *secondHalf = prev;
        while (secondHalf) {  // We only need to compare till the end of the reversed second half.
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: `O(n)`
  - Finding the middle of the list takes `O(n)` time (using two pointers).
  - Reversing the second half takes `O(n/2)` time (since we only reverse half the list).
  - Comparing the two halves takes `O(n/2)` time.
  - Overall, the time complexity is `O(n)`.

- **Space Complexity**: `O(1)`
  - No additional space is used apart from a few pointers (`slow`, `fast`, `prev`, `next`, etc.), all of which use constant space. This ensures `O(1)` auxiliary space.
</details>

<br>
<details>
<summary>Alternate Approach</summary>

A less optimal approach would be:
1. **Using a Stack**: Traverse the first half of the list and push the elements onto a stack, then pop elements and compare with the second half. This uses O(n) additional space (for the stack), making it less space-efficient compared to the in-place reversal method.

</details>

<br>

[[back to TOP](#palindrome-linked-list)]