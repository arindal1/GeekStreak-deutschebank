vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> bst1Elements, bst2Elements;
        inorderTraversal(root1, bst1Elements);
        inorderTraversal(root2, bst2Elements);

        return mergeSortedArrays(bst1Elements, bst2Elements);
    }
    Node* newNode(int data) {
        Node* node = new Node(data);
        return node;
    }
    void inorderTraversal(Node* root, vector<int>& elements) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, elements);
        elements.push_back(root->data);
        inorderTraversal(root->right, elements);
    }

    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        vector<int> mergedArray;
            int i = 0, j = 0;
            int n1 = arr1.size(), n2 = arr2.size();

        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                mergedArray.push_back(arr1[i]);
                i++;
            } else {
                mergedArray.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n1) {
            mergedArray.push_back(arr1[i]);
            i++;
        }
        while (j < n2) {
            mergedArray.push_back(arr2[j]);
            j++;
        }
        return mergedArray;
    }