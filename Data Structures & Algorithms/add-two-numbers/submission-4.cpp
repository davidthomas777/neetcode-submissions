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
#include <string>
class Solution {
public:
    ListNode * reverse(ListNode * head) {
        ListNode * current = head;
        ListNode * next = nullptr;
        ListNode * prev = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    int calculate_factor(ListNode * head) {
        ListNode * current = head;
        int factor = 1;
        while (current->next != nullptr) {
            factor *= 10;
            current = current->next;
        }
        return factor;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse both linked lists
        ListNode * l1_reversed = reverse(l1);
        ListNode * l2_reversed = reverse(l2);
        // sum variable
        int sum = 0;
        int factor_l1 = calculate_factor(l1_reversed);
        int factor_l2 = calculate_factor(l2_reversed);
        // create new empty linked list dummy
        ListNode * dummy = new ListNode(0);
        ListNode * tail = dummy;

        // calculate sum of l1_reversed digits
        while (l1_reversed != nullptr) {
            int num = l1_reversed->val * factor_l1;
            sum += num;
            factor_l1 /= 10;
            l1_reversed = l1_reversed->next;
        }
        // calculate sum of l2_reversed digits
        while (l2_reversed != nullptr) {
            int num = l2_reversed->val * factor_l2;
            sum += num;
            factor_l2 /= 10;
            l2_reversed = l2_reversed->next;
        }
        // edge case
        if (sum == 0) {
            return new ListNode(0);
        }

        // take each digit at the end of the number, modulo by 10, 
        // then set the next of tail to a new listnode with digit
        // update tail = tail->next
        while (sum > 0) {
            int digit = sum % 10;
            sum /= 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
        }
        return dummy->next;
    }
};
