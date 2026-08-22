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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // base case return nullptr if lists is empty
        if (lists.size() == 0) {
            return nullptr;
        }
        // result node that gets merged into every time
        ListNode * result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        // return result at end after merging all the way to end 
        return result;
    }

private:
    // helper function to merge two sorted lists
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode dummy(0);
        ListNode * current = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2-> val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        }
        else {
            current->next = l2;
        }
        return dummy.next;
    }
};
