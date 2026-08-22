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
#include <stack>
#include <algorithm>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case check if root is nullptr
        if (root == nullptr) {
            return nullptr;
        }
        // create a stack of type treenode
        stack<TreeNode*> stack;
        // add root first 
        stack.push(root);
        
        // iterate through stack while its not empty
        while (!stack.empty()) {
            // peek the top element
            TreeNode* node = stack.top();
            // pop it after assigned to node
            stack.pop();
            // swap children
            swap(node->left, node->right);
            // add to stack if nodes exist
            if (node->left) {
                stack.push(node->left);
            }
            if (node->right) {
                stack.push(node->right);
            }
        }
        return root;
    }
};
