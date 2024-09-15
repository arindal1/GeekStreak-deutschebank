# Binary Tree to DLL

Difficulty: **Hard** <br>
Tags: **Binary Tree, Doubly Linked List, Inorder traversal, Two Pointers** <br>
Solution: **[cpp](binaryTreeToDLL.cpp)**

Given a **Binary Tree (BT**), convert it to a **Doubly Linked List (DLL)** in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The **order of nodes** in DLL must be the same as the order of the given Binary Tree. The first node of **Inorder traversal** (leftmost node in BT) must be the head node of the DLL.  
  
**Note:** h is the tree's height, and this space is used implicitly for the recursion stack.

![TreeToList](http://www.geeksforgeeks.org/wp-content/uploads/TreeToList.png)

**Examples:**

```
Input:

      1
    /  \
   3    2

Output:  
3 1 2 
2 1 3 

Explanation: DLL would be 3<=>1<=>2
```
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700144/Web/Other/blobid0_1723093893.png)

```
Input:

       10
      /   \
     20   30
   /   \
  40   60

Output:
40 20 60 10 30 
30 10 60 20 40 

Explanation: DLL would be 40<=>20<=>60<=>10<=>30.
```
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700144/Web/Other/blobid1_1723093972.png)


## Approach

The approach to convert a **Binary Tree (BT)** to a **Doubly Linked List (DLL)** follows an **in-order traversal** pattern. In-order traversal visits the nodes of a binary tree in the following order: **left subtree → root → right subtree**. The goal is to modify the pointers of each node so that they can form a doubly linked list (DLL) while preserving the in-order traversal sequence.


### Detailed Steps:

#### 1. Perform an In-Order Traversal
- In-order traversal is used because it visits the nodes in the following order:
  - **Left subtree** (smaller values for a binary search tree).
  - **Root node** (current node).
  - **Right subtree** (larger values for a binary search tree).

#### 2. Maintain Two Pointers (`prev` and `head`)
- **`prev`**: This pointer keeps track of the previous node visited during the in-order traversal.
  - When we are at a node, `prev` is the node that was just visited.
- **`head`**: This pointer will point to the first node of the doubly linked list, which is the leftmost node of the binary tree (first node visited during in-order traversal).
  - The head node will be returned as the result, representing the start of the doubly linked list.

#### 3. Recursive Conversion Function (`convertToDLL`)
This function will be used to:
- Traverse the left subtree.
- Convert the current node.
- Traverse the right subtree.

Here’s what happens during the recursion:

1. **Traverse the Left Subtree**: 
   - First, we recursively move to the left subtree, processing the nodes in the left child before the current node.
   
2. **Convert the Current Node**:
   - When we visit a node during in-order traversal, we need to connect it to the previously visited node (`prev`):
     - If `prev` is `nullptr`, it means we are at the leftmost node (the first node of the doubly linked list), so we set `head` to this node.
     - Otherwise, we link the current node to `prev` by:
       - Setting the right pointer of `prev` to the current node.
       - Setting the left pointer of the current node to `prev`.

3. **Update `prev`**:
   - After linking the current node to `prev`, we update `prev` to point to the current node before moving to the right subtree.

4. **Traverse the Right Subtree**:
   - We recursively move to the right subtree to continue processing nodes.

#### 4. Termination Condition
- The base case for the recursion is when the node is `nullptr`, which means we’ve reached the end of a subtree. The recursion stops at that point and unwinds.

#### 5. Example Walkthrough
Let’s consider an example to understand this step-by-step.

<details>
<summary>Example 1</summary>

Input Tree:
```
      1
    /  \
   3    2
```

- Step 1: Start at the root (node 1).
- Step 2: Traverse left to node 3.
  - Node 3 has no left child, so process node 3. Since `prev` is `nullptr`, set `head = node 3`. Now, `prev = node 3`.
- Step 3: Move back to node 1 (the root). Link `prev` (node 3) with node 1.
  - Set `prev->right = node 1` and `node 1->left = prev` (node 3). Now, `prev = node 1`.
- Step 4: Traverse right to node 2.
  - Node 2 has no left child, so process node 2. Link `prev` (node 1) with node 2.
  - Set `prev->right = node 2` and `node 2->left = prev` (node 1). Now, `prev = node 2`.
- Step 5: The traversal is complete, and `head = node 3`. The doubly linked list is: `3 <=> 1 <=> 2`.
</details>

<details>
<summary>Example 2</summary>

Input Tree:
```
       10
      /   \
     20   30
   /   \
  40   60
```

- Step 1: Start at the root (node 10).
- Step 2: Traverse left to node 20, then further left to node 40.
  - Node 40 has no left child, so process node 40. Set `head = node 40`, `prev = node 40`.
- Step 3: Move back to node 20. Link `prev` (node 40) with node 20. Set `prev = node 20`.
- Step 4: Traverse right to node 60. Link `prev` (node 20) with node 60. Set `prev = node 60`.
- Step 5: Move back to node 10. Link `prev` (node 60) with node 10. Set `prev = node 10`.
- Step 6: Traverse right to node 30. Link `prev` (node 10) with node 30. Set `prev = node 30`.
- Step 7: The traversal is complete, and `head = node 40`. The doubly linked list is: `40 <=> 20 <=> 60 <=> 10 <=> 30`.
</details>

<br>
<details>
<summary>Code</summary>

```cpp
#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to perform in-order traversal and convert BT to DLL
void convertToDLL(Node* root, Node*& prev, Node*& head) {
    if (root == nullptr) {
        return;
    }

    // Recursively convert the left subtree
    convertToDLL(root->left, prev, head);

    // If prev is nullptr, we're at the leftmost node (head of DLL)
    if (prev == nullptr) {
        head = root;  // Set head of DLL
    } else {
        // Connect the previous node with the current node
        prev->right = root;
        root->left = prev;
    }

    // Update prev to the current node
    prev = root;

    // Recursively convert the right subtree
    convertToDLL(root->right, prev, head);
}

// Function to convert binary tree to doubly linked list
Node* bToDLL(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;

    // Convert the tree to DLL using in-order traversal
    convertToDLL(root, prev, head);

    return head;
}

// Utility function to print the Doubly Linked List from head to tail
void printDLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// Utility function to print the Doubly Linked List from tail to head
void printReverseDLL(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->right != nullptr) {
        temp = temp->right;
    }

    // Now temp is at the last node, traverse backwards
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->left;
    }
    cout << endl;
}

// Main function
int main() {
    // Example 1
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);

    Node* dll1 = bToDLL(root1);
    printDLL(dll1);          // Expected output: 3 1 2
    printReverseDLL(dll1);    // Expected output: 2 1 3

    // Example 2
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    root2->left->left = new Node(40);
    root2->left->right = new Node(60);

    Node* dll2 = bToDLL(root2);
    printDLL(dll2);          // Expected output: 40 20 60 10 30
    printReverseDLL(dll2);    // Expected output: 30 10 60 20 40

    return 0;
}

```
</details>
<br>
<details>
<summary>Time and Space Complexity</summary>

- **Time Complexity**: Each node in the binary tree is visited exactly once during the in-order traversal, so the time complexity is `O(n)`, where `(n)` is the number of nodes in the tree.
- **Space Complexity**: The space complexity is `O(h)`, where `(h)` is the height of the tree. This space is used for the recursion stack during the in-order traversal. For a balanced tree, `h = log n`, and for a skewed tree, `h = n`.
</details>