# Clone a linked list with next and random pointer

Difficulty: **Hard**
Tags: **Linked List**, **Deep Copy**, **Random Pointers**
Solution: **[cpp](cloneALinkedList.cpp)**

You are given a special linked list where each node has a next pointer pointing to its next node. You are also given some random pointers, where you will be given some pairs denoting two nodes **a** and **b** i.e. a->random = b **(*random* is a pointer to a random node).**

Construct a copy of the given list. The copy should consist of the same number of new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes **x** and **y** in the original list, where **x->random** = **y**, then for the corresponding two nodes **xnew** and **ynew** in the copied list, **xnew->** **random** **= ynew.**

Return the head of the copied linked list.

**NOTE :**   
1. If there is any node whose arbitrary pointer is not given then it's by default NULL.   
2. Don't make any changes to the original linked list.

![ArbitLinked List1](https://contribute.geeksforgeeks.org/wp-content/uploads/clone.jpg "ArbitLinked List1")

**Note**: The diagram isn't part of any example, it just depicts an example of how the linked list may look.

**Examples:**

**Input:** LinkedList: `1->2->3->4` , pairs = `[{1,2},{2,4}]` <br>
**Output:** `true` <br>
**Explanation:** In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer as NULL. Second line tells us the value of four nodes. The third line gives the information about arbitrary pointers. The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.

**Input:** LinkedList: 1->3->5->9 , pairs[] = [{1,1},{3,4}]
**Output:** true
**Explanation:** In the given testcase, applying the method as stated in the above example, the output will be 1.

**Expected Time Complexity**: `O(n)` <br>
**Expected Auxilliary Space**: `O(1)` <br>

**Constraints:**  
1 <= numbers of random pointer <= number of nodes <= 100  
0 <= node->data <= 1000  
1 <= a, b <= 100


## Approach

The approach involves **three main steps**:
1. **Clone nodes and interleave them** with the original list.
2. **Assign random pointers** to the new cloned nodes.
3. **Separate** the original list from the cloned list to form two separate lists.

### Step 1: Clone Nodes and Interleave Them

**Objective:** For each node in the original list, create a corresponding node in the new list and place it next to the original node.

- Start with the head of the original list.
- For each node `curr`, create a new node `newNode` with the same value as `curr`.
- Insert `newNode` right after `curr`, making the new node’s `next` pointer point to `curr->next`.

#### Example:
Consider the original list:
```
1 -> 2 -> 3 -> 4
```
After interleaving new nodes:
```
1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4'
```

At this point:
- The `next` pointers of the new nodes (denoted as `1'`, `2'`, etc.) are set, but the `random` pointers are not yet assigned.

### Step 2: Assign Random Pointers to the New Nodes

**Objective:** Properly set the `random` pointers for the cloned nodes.

- Traverse the interleaved list again.
- For each original node `curr`, if `curr->random` exists, set the corresponding random pointer for `curr->next` (the cloned node).
  - The random pointer for the cloned node `curr->next->random` should point to `curr->random->next`.
  - This works because `curr->random->next` will be the cloned version of `curr->random`.

#### Example:
For the original list, assume the `random` pointers are:
- `1->random = 2`
- `2->random = 4`

After setting the random pointers for the cloned nodes:
- `1'->random = 2'`
- `2'->random = 4'`

### Step 3: Separate the Original and Cloned Lists

**Objective:** Restore the original list and separate the cloned list.

- Traverse the interleaved list one more time and restore the `next` pointers of the original nodes.
- Extract the `next` pointers of the cloned nodes to form the new list.

#### Example:
From the interleaved list:
```
1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4'
```
We restore the original list as:
```
1 -> 2 -> 3 -> 4
```
And the cloned list as:
```
1' -> 2' -> 3' -> 4'
```


### Detailed Breakdown:

#### Step 1: Clone and Interleave Nodes
```cpp
Node* curr = head;
while (curr) {
    Node* newNode = new Node(curr->data);  // Create a new node with the same value
    newNode->next = curr->next;            // Make the new node point to the next node
    curr->next = newNode;                  // Insert the new node after the original node
    curr = newNode->next;                  // Move to the next original node
}
```

- This loop interleaves the new nodes between the original nodes, creating an alternating sequence of original and new nodes.

#### Step 2: Assign Random Pointers
```cpp
curr = head;
while (curr) {
    if (curr->random) {
        curr->next->random = curr->random->next;  // Set the random pointer for the new node
    }
    curr = curr->next->next;  // Move to the next original node
}
```

- We use `curr->next->random = curr->random->next` to correctly assign the random pointer of the new nodes.

#### Step 3: Separate the Lists
```cpp
curr = head;
Node* copyHead = head->next;
Node* temp = copyHead;
while (curr) {
    curr->next = curr->next->next;  // Restore the next pointer of the original node
    if (temp->next) {
        temp->next = temp->next->next;  // Set the next pointer for the copied node
    }
    curr = curr->next;    // Move to the next original node
    temp = temp->next;    // Move to the next copied node
}
```

- We restore the original list by skipping the cloned nodes and extract the cloned nodes to form the new list.



<br>
<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;

// Definition for a Node
struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int _data) {
        data = _data;
        next = NULL;
        random = NULL;
    }
};

// Function to copy the list with next and random pointers
Node* copyList(Node* head) {
    if (!head) return NULL;

    // Step 1: Create new nodes and interleave them with original nodes
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Assign random pointers to the new nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the copied list from the original list
    curr = head;
    Node* copyHead = head->next;
    Node* temp = copyHead;
    while (curr) {
        curr->next = curr->next->next;
        if (temp->next) {
            temp->next = temp->next->next;
        }
        curr = curr->next;
        temp = temp->next;
    }

    return copyHead;
}

// Function to print the list (for testing purposes)
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node value: " << curr->data;
        if (curr->random) {
            cout << ", Random points to: " << curr->random->data;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up random pointers
    head->random = head->next;            // 1's random points to 2
    head->next->random = head->next->next->next; // 2's random points to 4

    // Copying the list
    Node* copiedList = copyList(head);

    // Printing the copied list
    cout << "Copied List:" << endl;
    printList(copiedList);

    return 0;
}

```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: `O(n)` because we traverse the list 3 times (once for interleaving, once for setting `random` pointers, and once for separating the lists).
- **Space Complexity**: `O(1)` extra space (excluding the space required for the new nodes), since we do not use any additional data structures like hashmaps or arrays.
</details>