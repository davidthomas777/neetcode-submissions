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
#include <set>

class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::set<ListNode *> my_set;
        ListNode * curr = head;
        while (curr != nullptr) {
            if (my_set.count(curr) == 1) {
                return true;
            }
            else {
                my_set.insert(curr);
                curr = curr->next;
            }
        }
        return false;
    }
};
