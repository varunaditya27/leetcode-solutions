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
        if (root == nullptr) {
            return root;
        }

        queue<Node*> level;
        level.push(root);

        while (level.empty() != true) {
            int level_size = level.size();            
            for (int i = 0; i < level_size - 1; i++) {
                Node* curr = level.front();

                if (curr->left != nullptr)
                    level.push(curr->left);
                
                if (curr->right != nullptr)
                    level.push(curr->right);

                level.pop();

                Node* next = level.front();
                curr->next = next;
            }
            Node* last = level.front();
            last->next = NULL;
            if (last->left != nullptr)
                level.push(last->left);
                
            if (last->right != nullptr)
                level.push(last->right);

            level.pop();
        }

        return root;
    }
};
