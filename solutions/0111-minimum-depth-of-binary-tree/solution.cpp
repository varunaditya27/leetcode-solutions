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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        int len;
        TreeNode* curr;

        while (!q.empty()) {
            len = q.size();
            res++;

            for (int i = 0; i < len; i++) {
                curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                if (!curr->left && !curr->right) return res;
            }
        }

        return res;
    }
};
