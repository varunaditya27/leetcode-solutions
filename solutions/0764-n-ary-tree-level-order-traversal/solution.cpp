/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<Node*> q;

        q.push(root);
        int len;

        while (!q.empty()) {
            len = q.size();
            vector<int> level;

            for (int i = 0; i < len; i++) {
                Node* curr = q.front();
                level.push_back(curr->val);

                for (auto child: curr->children) {
                    q.push(child);
                }

                q.pop();
            }

            res.push_back(level);
        }

        return res;
    }
};
