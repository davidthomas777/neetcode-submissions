/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // min heap
    std::priority_queue<int, vector<int>, greater<int>> pq;

    int kthSmallest(TreeNode* root, int k) {
        if (!root->left && !root->right) return 1;
        dfs(root);
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        return pq.top();
    }

    // we want to add every node from the binary search tree into the priority queue
    void dfs(TreeNode* root) {
        if (!root) return;
        pq.push(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
