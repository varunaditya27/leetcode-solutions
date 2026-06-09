/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfsSearch(TreeNode* root, vector<TreeNode*>& ancestors, int target, vector<TreeNode*>& res) {
        if (!root) return;

        ancestors.push_back(root);

        if (root->val == target) {
            res = ancestors;
            return;
        }
        else {
            dfsSearch(root->left, ancestors, target, res);
            dfsSearch(root->right, ancestors, target, res);
        }

        ancestors.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancestors_p;
        vector<TreeNode*> ancestors_q;

        vector<TreeNode*> res_p;
        vector<TreeNode*> res_q;

        dfsSearch(root, ancestors_p, p->val, res_p);
        dfsSearch(root, ancestors_q, q->val, res_q);

        cout << "P: \n";
        for (auto node: res_p) cout << node->val << " ";
        cout << "\n\nQ: \n";
        for (auto node: res_q) cout << node->val << " ";

        int height_p = res_p.size();
        int height_q = res_q.size();

        int diff = max(height_p, height_q) - min(height_p, height_q);

        for (int i = min(height_p, height_q) - 1; i >= 0; i--) {
            if (res_p[i] == res_q[i]) return res_p[i];
        }

        return root;
    }
};
