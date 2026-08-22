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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode * node, long left, long right) {
        if (!node) {
            return true;
        }
        // if current node is smaller than the left or larger than the right (wrong logic)
        // return false as BST is not valid
        if (!(left < node->val && node->val < right)) {
            return false;
        }
        
        // call valid on left subtree with current node as maximum and 
        // call valid on right subtree with current node as minimum 
        // (right must be greater than previous & left must be smaller than previous)
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }
};
