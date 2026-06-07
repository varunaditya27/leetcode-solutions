class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int len = descriptions.size();
        unordered_map<int, TreeNode*> map;
        vector<int> is_root(100001, -1);
        TreeNode* root;

        for (int i = 0; i < len; i++) {
            int parent = descriptions[i][0];
            int child  = descriptions[i][1];

            if (!map.contains(parent)) {
                map[parent] = new TreeNode(parent);
            }
            if (!map.contains(child)) {
                map[child] = new TreeNode(child);
            }

            TreeNode* parent_node = map[parent];
            TreeNode* child_node  = map[child];

            if (is_root[parent] == -1) is_root[parent] = 1;
            is_root[child] = 0;

            if (descriptions[i][2] == 1) parent_node->left  = child_node;
            else parent_node->right = child_node;
        }

        for (int i = 1; i <= 100000; i++) {
            if (is_root[i] == 1) {
                root = map[i];
                break;
            }
        }

        return root;
    }
};
