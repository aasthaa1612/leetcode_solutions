struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd-length list, skip middle node
    if (fast)
        slow = slow->next;

    // Reverse second half
    slow = reverse(slow);

    // Compare both halves
    while (slow) {
        if (head->val != slow->val)
            return false;

        head = head->next;
        slow = slow->next;
    }

    return true;
}