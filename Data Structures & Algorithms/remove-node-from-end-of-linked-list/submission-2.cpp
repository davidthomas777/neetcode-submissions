/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        int len = 0;
        ListNode * curr = head;
        while (curr != nullptr) {
            ++len;
            curr = curr->next;
        }
        int end_num = len - n;

        if (end_num == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        curr = head;
        for (int i = 0; i < end_num - 1; ++i) {
            curr = curr->next;
        }
        ListNode * to_delete = curr->next;
        curr->next = to_delete->next;
        delete to_delete;
        return head;
    }
};
