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
private:         
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        minHeap.push(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int count = 1;
        while (count != k) {
            minHeap.pop();
            count++;
        }
        return minHeap.top();
    }
};
