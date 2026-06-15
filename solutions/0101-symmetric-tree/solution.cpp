#define none 101

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
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return true;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;

        while (!q.empty()) {
            vector<int> rev(level.rbegin(), level.rend());
            if (level != rev) return false;

            level.clear();
            int len = q.size();

            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) {
                    q.push(curr->left);
                    level.push_back(curr->left->val);
                }
                else level.push_back(none);

                if (curr->right) {
                    q.push(curr->right);
                    level.push_back(curr->right->val);
                }
                else level.push_back(none);
            }
        }

        return true;
    }
};
