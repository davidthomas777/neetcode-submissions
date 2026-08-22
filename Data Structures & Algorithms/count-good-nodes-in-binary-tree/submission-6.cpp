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
    int goodNodes(TreeNode* root) {
        // call helper function with root->val
        return dfs(root, root->val);
    }
    int dfs(TreeNode * root, int maxVal) {
        // if no root, res is 0
        if (!root) {
            return 0;
        }
        int res = 0;
        // if current node is bigger than previous, res = 1
        if (root->val >= maxVal) {
            res = 1;
        }
        // if not, not a good node
        else {
            res = 0;
        }
        // maxVal is set
        maxVal = max(maxVal, root->val);
        // count # of good nodes in left and right subtree
        res += dfs(root->left, maxVal);
        res += dfs(root->right, maxVal);
        return res;
        
    }
};
