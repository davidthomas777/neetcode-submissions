/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        // Already cloned this node
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new clone (without neighbors for now)
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Recursively clone all neighbors. push back the object into neighbors
        for (Node* n : node->neighbors) {
            // push back cloneGraph(n) because just n would push back a reference. This is a deep copy
            clone->neighbors.push_back(cloneGraph(n));
        }

        return clone;
    }
};
