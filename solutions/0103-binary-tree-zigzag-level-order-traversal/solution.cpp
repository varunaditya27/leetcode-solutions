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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        vector<vector<int>> raw_levels;
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false) {
            int level_size = q.size();
            vector<int> level;

            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                q.pop();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            raw_levels.push_back(level);
        }

        int level_count = raw_levels.size();
        int k = 0;
        int reversed = 0;

        while (k < level_count) {
            if (reversed == 0) {
                reversed = 1;
            }
            else {
                vector<int> original = raw_levels[k];
                reverse(original.begin(), original.end());
                raw_levels[k] = original;
                reversed = 0;
            }
            k++;
        }

        return raw_levels;
    }
};
