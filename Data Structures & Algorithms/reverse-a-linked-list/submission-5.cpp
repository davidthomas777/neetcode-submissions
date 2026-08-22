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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * next = nullptr;
        while (curr != nullptr) {
            // save next node
            next = curr->next;
            // reverse pointer direction
            curr->next = prev;
            // move prev forward
            prev = curr;
            // move the curr forward
            curr = next;
        }
        return prev;
    }
};
