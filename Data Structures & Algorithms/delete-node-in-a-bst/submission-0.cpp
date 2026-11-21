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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        // if key is greater than current val
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // if key is less than current val
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // found node to delete
        if (root->val == key) {
            if (!root->left) {
                TreeNode* r = root->right;
                delete root;
                return r;
            }
            if (!root->right) {
                TreeNode* l = root->left;
                delete root;
                return l;
            }
            // two children, so go to right of root and find its leaf node on the left all the way down
            TreeNode* next = root->right;
            while (next->left) {
                next = next->left;
            }
            root->val = next->val;
            root->right = deleteNode(root->right, next->val);

        }
        return root;
    }
};