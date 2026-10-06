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
    void dfs(TreeNode* curr, int val) {
        if (!curr->left && val < curr->val) {
            TreeNode * new_node = new TreeNode(val);
            curr->left = new_node;
            return;
        }
        else if (!curr->right && val > curr->val) {
            TreeNode * new_node = new TreeNode(val);
            curr->right = new_node;
            return;
        }
        if (val < curr->val && curr->left) {
            dfs(curr->left, val);
        }
        else if (val > curr->val && curr->right) {
            dfs(curr->right, val);
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        dfs(root, val);
        return root;
    }
};