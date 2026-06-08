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
    void dfs(TreeNode* root, int targetSum, int currSum, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;

        path.push_back(root->val);
        currSum += root->val;

        if (!root->left && !root->right) {
            if (currSum == targetSum) {
                res.push_back(path);
            }
        }
        else {
            dfs(root->left, targetSum, currSum, path, res);
            dfs(root->right, targetSum, currSum, path, res);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);
        return res;
    }
};
