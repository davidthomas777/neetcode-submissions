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
        // [1, 2, 3, 4] size = 4, n = 2, 
        // nth_node = size - (n - 1)
        // = 4 - (2 - 1) = 4 - (1) = 3
        ListNode * curr = head;
        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        if (size == n) return head->next;

        ListNode * current = head;

        int nth_node = size - n;
        int count = 1;
        
        while (count != nth_node) {
            count++;
            cout << current->val << endl;

            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};
