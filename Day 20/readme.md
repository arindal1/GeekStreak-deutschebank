# Merge two BST 's

Difficulty: **Medium** <br>
Tags: **Tree**, **Depth-First Search**, **Hash Table** <br>
Solution: **[cpp](mergeTwoBSTs.cpp)**

Given two BSTs, return elements of merged BSTs in **sorted** form.

**Examples :**

**Input:** <br>
BST1:
```
       5
     /   \
    3     6
   / \
  2   4  
```
BST2:
```
        2
      /   \
     1     3
            \
             7
            /
           6
```
**Output:** `1 2 2 3 3 4 5 6 6 7` <br>
**Explanation:** After merging and sorting the two BST we get `1 2 2 3 3 4 5 6 6 7`.

**Input:** <br>
BST1: <br>
```
       12
     /   
    9
   / \    
  6   11
```
BST2: <br>
```
      8
    /  \
   5    10
  /
 2
```
**Output:** `2 5 6 8 9 10 11 12` <br>
**Explanation:** After merging and sorting the two BST we get `2 5 6 8 9 10 11 12`.

**Expected Time Complexity:** `O((m+n)*log(m+n))`   <br>
**Expected Auxiliary Space:** `O(Height of BST1 + Height of BST2 + m + n)` <br>

**Constraints:**  
1 ≤ Number of Nodes, Value of Nodes ≤ 10^5

## Approach:

1. **Inorder Traversal**:
   - A Binary Search Tree (BST) stores elements in a way that an **inorder traversal** (left, root, right) retrieves the elements in sorted order. 
   - We can leverage this property by performing an inorder traversal on both BSTs to get two sorted arrays.
   
2. **Merging Two Sorted Arrays**:
   - Once we have the sorted arrays from both BSTs, the problem reduces to merging two sorted arrays. 
   - The classic two-pointer technique is used to merge the two sorted arrays into one, which ensures that the merged array is sorted.

3. **Return the Merged Array**:
   - After merging, the final array will contain all the elements from both BSTs in sorted order.

### Algorithm Steps:

1. Perform **inorder traversal** on both BSTs to get two sorted arrays.
2. Merge the two sorted arrays using the two-pointer technique:
   - Compare the elements at each index of both arrays.
   - Insert the smaller element into the result array and move the corresponding pointer.
   - Repeat until all elements from both arrays are merged.
3. Return the merged array.

<br>
<details>
<summary>Example Walkthrough</summary>

Consider two BSTs as follows:

#### BST1:
```
      5
     / \
    3   6
   / \
  2   4
```

#### BST2:
```
      2
     / \
    1   3
         \
          7
         /
        6
```

1. **Inorder traversal of BST1**:
   - Start at root 5, move to the left child 3, move further left to 2, which is the leftmost node.
   - The inorder sequence is: **2 → 3 → 4 → 5 → 6**.

2. **Inorder traversal of BST2**:
   - Start at root 2, move to the left child 1, move to the right child 3, move further right to 7.
   - The inorder sequence is: **1 → 2 → 3 → 6 → 7**.

3. **Merge the two sorted arrays**:
   - Array from BST1: **[2, 3, 4, 5, 6]**
   - Array from BST2: **[1, 2, 3, 6, 7]**
   - Merging both arrays: **[1, 2, 2, 3, 3, 4, 5, 6, 6, 7]**

The merged result is: **[1, 2, 2, 3, 3, 4, 5, 6, 6, 7]**
</details>


<br>
<details>
<summary>Code</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition of the tree node
struct Node {
    int data;
    Node* left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Inorder traversal to store the elements of BST in sorted order
void inorderTraversal(Node* root, vector<int>& elements) {
    if (root == NULL) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}

// Function to merge two sorted arrays into one
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged(arr1.size() + arr2.size());
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), merged.begin());
    return merged;
}

// Main function to merge two BSTs
vector<int> merge(Node* root1, Node* root2) {
    vector<int> bst1Elements, bst2Elements;

    // Get the sorted elements of both BSTs using inorder traversal
    inorderTraversal(root1, bst1Elements);
    inorderTraversal(root2, bst2Elements);

    // Merge the two sorted lists
    return mergeSortedArrays(bst1Elements, bst2Elements);
}

// Helper function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

// Main driver function for testing
int main() {
    Node* root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(6);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);

    Node* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);
    root2->right->right = newNode(7);
    root2->right->right->left = newNode(6);

    vector<int> mergedResult = merge(root1, root2);

    for (int val : mergedResult) cout << val << " ";

    return 0;
}
```
</details>

<br>
<details>
<summary>Time and Space Complexity</summary>

1. **Time Complexity**:
   - The time complexity of inorder traversal for both trees is **O(m + n)**, where \(m\) and \(n\) are the sizes of the two trees.
   - Merging the two sorted arrays takes **O(m + n)**.
   - Therefore, the total time complexity is **O(m + n)**.

2. **Space Complexity**:
   - We use two auxiliary arrays to store the inorder traversal results, which take **O(m + n)** space.
   - Additionally, the recursion stack for inorder traversal will take **O(h1 + h2)**, where \(h1\) and \(h2\) are the heights of the two trees.
   - Therefore, the total space complexity is **O(m + n + h1 + h2)**.
</details>

<br>

[[back to TOP](#total-count)]