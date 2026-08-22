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
    // function to reverse second half of linked list
    ListNode * reverseLinkedList(ListNode * head) {
        ListNode * prev = nullptr;
        ListNode * current = head;
        ListNode * next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
        // returns a pointer of type ListNode of the reversed linked list
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        ListNode * slow = head;
        ListNode * fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            // iterate twice as fast to get to the middle for slow
            fast = fast->next->next;
            // iterates once every time fast moves two nodes ahead
            slow = slow->next;
        }

        // split into two halves
        ListNode * second_half = slow->next;
        // null the first half
        slow->next = nullptr;

        // reverse the second half
        second_half = reverseLinkedList(second_half);
        // first half equal to head
        ListNode * first_half = head;

        while (second_half) {
            // save next pointers before changing them
            ListNode * temp1 = first_half->next;
            ListNode * temp2 = second_half->next;

            // connect first_half next to second_half
            first_half->next = second_half;
            // connect second_half to the next of the first (temp1)
            second_half->next = temp1;

            first_half = temp1;
            second_half = temp2;
        }
    }
};
