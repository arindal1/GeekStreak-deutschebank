class Solution {
public:
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = nullptr, *next = nullptr, *curr = slow;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *firstHalf = head, *secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
