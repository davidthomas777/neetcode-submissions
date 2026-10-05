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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        // handles left == 1
        ListNode dummy(0, head);
        // node just before position `left`
        ListNode* before = &dummy;
        for (int i = 1; i < left; i++) before = before->next;

        // first node to reverse
        ListNode* curr = before->next;
        // node just after position `right`
        ListNode* after = curr;
        for (int i = left; i <= right; i++) after = after->next;

        // reversed tail links to `after`
        ListNode* prev = after;
        while (curr != after) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        before->next = prev;

        return dummy.next;
    }
};