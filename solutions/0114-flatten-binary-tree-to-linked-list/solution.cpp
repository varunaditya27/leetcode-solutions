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
    void preorder(TreeNode* root, vector<TreeNode*>& traversal) {
        if (root == nullptr) {
            return;
        }

        traversal.push_back(root);
        preorder(root->left, traversal);
        preorder(root->right, traversal);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        vector<TreeNode*> nodes;
        preorder(root, nodes);
        int node_count = nodes.size();

        for (int i = 0; i < node_count - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes[node_count - 1]->left = nullptr;
        nodes[node_count - 1]->right = nullptr;
    }
};
