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
    void preorder(TreeNode* root, vector<int>& traversal) {
        if (root == nullptr) {
            return;
        }

        traversal.push_back(root->val);
        if (root->left == nullptr) {
            traversal.push_back(-999999);
        }
        if (root->right == nullptr) {
            traversal.push_back(999999);
        }

        preorder(root->left, traversal);
        preorder(root->right, traversal);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if ((!p && q) || (p && !q)) {
            return false;
        }

        vector<int> tree1, tree2;
        preorder(p, tree1);
        preorder(q, tree2);

        if (tree1.size() != tree2.size()) {
            return false;
        }

        int len = tree1.size();
        for (int i = 0; i < len; i++) {
            if (tree1[i] != tree2[i]) {
                return false;
            }
        }

        return true;
    }
};
