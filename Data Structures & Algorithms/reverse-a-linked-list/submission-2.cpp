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
#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //base case
        if (!head) {
            return nullptr;
        }

        // create a stack, put values from linked list in the stack
        std::stack<int> my_stack;
        ListNode * temp = head;
        while (temp != nullptr) {
            my_stack.push(temp->val);
            temp = temp->next;
        }

        //create a new head and assign it to the result
        ListNode * result = head;
        temp = result;

        // Now iterate through the stack and set the result linked list to the val of each 
        // val in the stack, then pop it so you can reverse the linked list
        while (!my_stack.empty()) {
            temp->val = my_stack.top();
            my_stack.pop();
            temp = temp->next;
        }
        return result;
    }
};
