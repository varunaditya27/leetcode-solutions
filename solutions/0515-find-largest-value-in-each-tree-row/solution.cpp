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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->val};

        queue<TreeNode*> q;

        q.push(root);
        int len;
        vector<int> res;

        while (!q.empty()) {
            len = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                max_val = max(max_val, curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                q.pop();
            }

            res.push_back(max_val);
        }

        return res;
    }
};
