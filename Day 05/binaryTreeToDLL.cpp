class Solution {
  public:
    void convertToDLL(Node* root, Node*& prev, Node*& head) {
        if (root == nullptr) {
            return;
        }

        convertToDLL(root->left, prev, head);
        if (prev == nullptr) {
            head = root;
        } else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        convertToDLL(root->right, prev, head);
    }

    Node* bToDLL(Node* root) {
        Node* head = nullptr;
        Node* prev = nullptr;
    
        convertToDLL(root, prev, head);
        return head;
    }
};