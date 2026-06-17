/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !(root->left || root->right)) {
            return root;
        }
        deque<Node*> level;
        vector<vector<Node*>> levels;
        
        level.push_back(root);

        while (!level.empty()) {
            int size = level.size();
            vector<Node*> curr_level;
            for (int i = 0; i < size; i++) {
                Node* curr = level.front();
                if (curr->left) {
                    level.push_back(curr->left);
                    curr_level.push_back(curr->left);
                }
                if (curr->right) {
                    level.push_back(curr->right);
                    curr_level.push_back(curr->right);
                }
                level.pop_front();
            }
            levels.push_back(curr_level);
        }
        
        int level_count = levels.size();
        for (int i = 0; i < level_count; i++) {
            int count = levels[i].size();
            for (int j = 0; j < count - 1; j++) {
                levels[i][j]->next = levels[i][j + 1];
            }
        }

        return root;
    }
};
