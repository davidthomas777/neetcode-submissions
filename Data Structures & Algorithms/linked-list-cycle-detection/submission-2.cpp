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
        // create a set of visited nodes in the linked list
        std::set<ListNode *> my_set;
        // create a temp node equal to head
        ListNode * curr = head;
        // iterate through entire linked list
        while (curr != nullptr) {
            // if we have seen this node before, return false
            if (my_set.count(curr) == 1) {
                return true;
            }
            // if not, add it to the set and keep iterating
            else {
                my_set.insert(curr);
                curr = curr->next;
            }
        }
        // if we iterate through the whole linked list without any duplicates,
        // then, we should return false since there are no cycles
        return false;
    }
};
