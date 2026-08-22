/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // base case
        if (!head) return nullptr;
        
        // create new nodes and map them
        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;
        
        while (current) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        // Second pass: Set next and random pointers
        current = head;
        while (current) {
            if (current->next) {
                nodeMap[current]->next = nodeMap[current->next];
            }
            if (current->random) {
                nodeMap[current]->random = nodeMap[current->random];
            }
            current = current->next;
        }
        
        return nodeMap[head];
    }
};
