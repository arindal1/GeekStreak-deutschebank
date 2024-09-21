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
