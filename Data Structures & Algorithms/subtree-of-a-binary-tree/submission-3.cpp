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
    // this helper function is the same as same tree 
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        // if both trees are empty, return true
        if (!root && !subRoot) {
            return true;
        }
        // if both trees are not empty, and their values are the same
        // recursively call sameTree on the left trees and the right trees and
        // return if they both end up being true
        if (root && subRoot && root->val == subRoot->val) {
            bool left_subtree = sameTree(root->left, subRoot->left);
            bool right_subtree = sameTree(root->right, subRoot->right);
            return (left_subtree && right_subtree);
        }
        // return
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (sameTree(root, subRoot)) {
            return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        if (left || right) {
            return true;
        }
    }
};
