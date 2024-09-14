# MirrorTree

**Difficulty:** Easy <br>
**Tags:** Tree, Depth-First Search <br>
**Solution:** [cpp](mirrorTree.cpp) <br>

Given a Binary Tree, convert it into its mirror.  
![MirrorTree1](https://contribute.geeksforgeeks.org/wp-content/uploads/mirrortrees.jpg "MirrorTree1")            

**Example 1:**

**Input:**
```
      1
    /  \
   2    3
```
**Output:** 3 1 2 <br>
**Explanation:**
```
  1    (mirror)     1
 /  \     =>      /  \
2    3           3    2
```
The inorder of mirror is 3 1 2

**Example 2:**

**Input:**
```
      10
     /  \
    20   30
   /  \
  40  60
```
**Output:** 30 10 60 20 40 <br>
**Explanation:** 
```
      10                10
    /    \  (mirror)  /    \
   20    30    =>    30    20
  /  \                    /   \
 40  60                 60    40
```
The inroder traversal of mirror is: 30 10 60 20 40.


**Expected Time Complexity:** O(n)  
**Expected Auxiliary Space:** O(height of the tree)

**Constraints:**  
1 ≤ Number of nodes ≤ 10^5  
1 ≤ Data of a node ≤ 10^5


## Approach

A binary tree's mirror is another tree that has the same structure, but with left and right subtrees swapped at every node. The goal is to recursively swap the left and right children of each node in the binary tree.

### Approach:
The recursive approach involves three main steps:
1. **Base Case:** If the node is `NULL`, we return immediately. This prevents further recursion and terminates at the leaf nodes.
2. **Recursive Call:** Recursively mirror the left and right subtrees before swapping. This ensures that the entire subtree beneath a node is mirrored.
3. **Swap:** Once the left and right subtrees are mirrored, we swap the left and right child pointers of the current node.

### Steps in Detail:
1. **Base Case (Leaf nodes or empty tree):**
   - If the input node is `NULL`, there's nothing to mirror, so the function returns immediately. This is important to avoid unnecessary processing and to handle the recursion termination at the bottom of the tree.

2. **Recursion (Handling subtrees):**
   - For a given node, we first need to mirror its left and right subtrees recursively.
   - For example, if the node has children:
     ```
         10
        /  \
       20   30
     ```
     The function will first recursively process the left child (`20`) and the right child (`30`) before any swapping occurs.

3. **Swapping (Switch left and right):**
   - After both the left and right subtrees are mirrored, we swap the left and right children of the current node.
   - For the example above, after processing its subtrees:
     ```
         10
        /  \
       30   20
     ```
   - This swapping ensures that the node's left and right children are mirrored.
  
### Traversal Order:
This approach follows a **post-order traversal** (left subtree -> right subtree -> node):
- First, recursively mirror the left and right subtrees.
- Then, swap the left and right child pointers of the current node.

### Example Walkthrough:
Let’s consider the following tree:
```
        10
       /  \
      20   30
     /  \
    40  60
```

#### Step-by-step Execution:
1. Start at the root node (`10`).
2. Recursively process the left subtree (`20`):
   - Process the left subtree of `20` (`40`), which is a leaf node, so nothing changes.
   - Process the right subtree of `20` (`60`), which is also a leaf node, so nothing changes.
   - After mirroring the subtrees of `20`, swap `40` and `60`.
     Result:
     ```
        20
       /  \
     60   40
     ```
3. Recursively process the right subtree (`30`), which is a leaf node, so nothing changes.
4. Now swap the left and right children of the root node (`10`), so `30` and `20` are swapped.
   Final tree:
   ```
        10
       /  \
      30   20
           /  \
         60   40
   ```

```cpp
// function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if (node == NULL)
            return;
        mirror(node->left);
        mirror(node->right);
    
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
```

### Time Complexity:
- The function visits every node exactly once, performing a constant amount of work (swapping the children). Therefore, the time complexity is `O(n)`, where `n` is the number of nodes in the tree.

### Space Complexity:
- The space complexity is determined by the recursion depth, which is proportional to the height of the tree.
- In the worst case (for a skewed tree), the recursion depth could be `O(n)`. For a balanced tree, the depth is `O(log n)`. Hence, the auxiliary space complexity is `O(height of the tree)`.
