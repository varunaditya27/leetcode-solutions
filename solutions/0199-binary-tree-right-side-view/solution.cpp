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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> res;

        while(!q.empty()) {
            vector<TreeNode*> level;
            int len = q.size();
            TreeNode* curr;

            for (int i = 0; i < len; i++) {
                curr = q.front();
                if (curr->left) q.push_back(curr->left);
                if (curr->right) q.push_back(curr->right);
                q.pop_front();
            }

            res.push_back(curr->val);
        }

        return res;
    }
};
