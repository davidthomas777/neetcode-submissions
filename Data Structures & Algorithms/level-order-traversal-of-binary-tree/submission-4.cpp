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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // RUN breadth first search algorithm on root
        std::vector<vector<int>> res_list;
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);

        // iterate bfs while queue is not empty
        while (!myQueue.empty()) {
            // get the size of the queue
            int q_len = myQueue.size();
            // vector to be inserted into res list
            std::vector<int> level;
            // iterate through queue elements
            for (int i = 0; i < q_len; i++) {
                TreeNode * node = myQueue.front();
                myQueue.pop();
                if (node) {
                    level.push_back(node->val);
                    if (node->left) {
                        myQueue.push(node->left);
                    }
                    if (node->right) {
                        myQueue.push(node->right);
                    }
                }
            }
            if (!level.empty()) {
                res_list.push_back(level);
            }
        }
        return res_list;
    }
};
