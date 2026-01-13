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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);

        while (q.empty() != true) {
            int level_size = q.size();
            vector<int> curr_level;
            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }

                q.pop();
                curr_level.push_back(curr->val);
            }

            s.push(curr_level);
        }

        while (s.empty() != true) {
            vector<int> lvl;
            lvl = s.top();
            s.pop();
            result.push_back(lvl);
        }

        return result;
    }
};
