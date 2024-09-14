# Find the Middle Node

**Difficulty:** Easy <br>
**Tags:** Linked List, Two Pointer <br>
**Solution:** [cpp](middleOfALinkedList.cpp) <br>

Given the head of a linked list, the task is to find the **middle**. For example, the middle of **1-> 2->3->4->5** is **3**. If there are two middle nodes (even count), return the **second middle**. For example, middle of **1->2->3->4->5->6** is **4**.

**Examples:**

**Input:** Linked list: 1->2->3->4->5
**Output:** 3  
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700171/Web/Other/blobid0_1721970743.png)  
**Explanation:** The given linked list is 1->2->3->4->5 and its middle is 3.

**Input:** Linked list: 2->4->6->7->5->1
**Output:** 7   
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700171/Web/Other/blobid1_1721970760.png)  
**Explanation:** The given linked list is 2->4->6->7->5->1 and its middle is 7.

**Expected Time Complexity:** O(n)  
**Expected Auxiliary Space:** O(1)

**Constraints:**  
1 <= no. of nodes <= 10^5


## Approach

This approach uses the **two-pointer technique** (often called "slow and fast pointers") to find the middle of a linked list. Here's how it works step by step:

As the fast pointer moves at double the speed of the slow pointer, by the time the fast pointer reaches the end of the list, the slow pointer will be at the middle of the list.

### Detailed Steps:
1. **Initialization:**
   - Both `slow` and `fast` pointers are initialized to the head of the linked list.

2. **Traversal:**
   - In each iteration, the `slow` pointer moves one node ahead (`slow = slow->next`).
   - The `fast` pointer moves two nodes ahead (`fast = fast->next->next`).

3. **Stopping Condition:**
   - The loop continues as long as `fast` and `fast->next` are not `nullptr`. This ensures that the `fast` pointer doesn't go past the end of the list.
   - When `fast` reaches the end of the list (or just before the end in case of an odd number of nodes), the `slow` pointer will be at the middle of the list.

4. **Return:**
   - After the loop ends, the `slow` pointer will be pointing to the middle node, which is returned as the result.

### Example:

For the linked list `1 -> 2 -> 3 -> 4 -> 5`:

- Initially, `slow` and `fast` both point to `1`.
- After the first iteration:
  - `slow` moves to `2`.
  - `fast` moves to `3`.
- After the second iteration:
  - `slow` moves to `3`.
  - `fast` moves to `5`.
- After the third iteration:
  - `fast` reaches the end of the list, so the loop stops.
  - `slow` is now at `3`, which is the middle of the list.

```cpp
/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
```

### Time Complexity:
- **O(n)**: The list is traversed once. Both `slow` and `fast` pointers move together, but since the `fast` pointer moves twice as fast, the loop runs for `n/2` steps (where `n` is the number of nodes), which is still `O(n)`.

### Space Complexity:
- **O(1)**: No extra space is used apart from the two pointers.