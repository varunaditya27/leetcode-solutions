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
    void helperFunc(TreeNode* root, vector<int>& traversal) {
        if (root == nullptr) {
            return;
        }

        helperFunc(root->left, traversal);
        traversal.push_back(root->val);
        helperFunc(root->right, traversal);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helperFunc(root, result);

        return result;
    }
};
