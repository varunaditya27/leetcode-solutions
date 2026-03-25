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
    int helperFunc(TreeNode* root, int node_sum) {
        if (!root) {
            return 0;
        }

        node_sum = (node_sum * 10) + root->val;
        if (!root->left && !root->right) {
            return node_sum;
        }

        return helperFunc(root->left, node_sum) + helperFunc(root->right, node_sum);
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return helperFunc(root, 0);
    }
};
