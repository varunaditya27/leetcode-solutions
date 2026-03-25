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
    bool helperFunc(TreeNode* node, long min_value, long max_value) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= min_value || node->val >= max_value) {
            return false;
        }
        return helperFunc(node->left, min_value, node->val) && helperFunc(node->right, node->val, max_value);
    }

    bool isValidBST(TreeNode* root) {
        return helperFunc(root, LONG_MIN, LONG_MAX);
    }
};
