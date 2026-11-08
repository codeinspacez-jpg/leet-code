class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        while (curr->next != NULL && curr->next->next != NULL) {
            ListNode* first = curr->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            curr->next = second;

            curr = first;
        }

        return dummy->next;
    }
};