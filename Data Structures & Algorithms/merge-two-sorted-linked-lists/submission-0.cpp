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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // create new linked list
        ListNode * linked_list = new ListNode(0);
        // create a dummy linked list
        ListNode * current = linked_list;

        //itereate through both given lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                // set head to list 1 (smaller val)
                current->next = list1;
                // update list1 curr ptr to next
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            // update the copied linked list
            current = current->next;
        }
        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        ListNode * result = linked_list->next;
        delete linked_list;
        return result;
    }
};
