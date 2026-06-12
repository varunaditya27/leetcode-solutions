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
    int findBottomLeftValue(TreeNode* root) {
        if (!root->left && !root->right) return root->val;

        queue<TreeNode*> q;

        q.push(root);
        int len;
        bool isFirst = true;
        int res;

        while (!q.empty()) {
            len = q.size();

            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                if (isFirst) {
                    res = curr->val;
                    isFirst = false;
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                q.pop();
            }

            isFirst = true;
        }

        return res;
    }
};
