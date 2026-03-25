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
    TreeNode* helperFunc(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int middle = (left + right) / 2;
        TreeNode* curr = new TreeNode();

        curr->val = nums[middle];
        curr->left = helperFunc(nums, left, middle - 1);
        curr->right = helperFunc(nums, middle + 1, right);

        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode* root = helperFunc(nums, 0, len - 1);

        return root;
    }
};
