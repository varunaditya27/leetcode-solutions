/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* start = new Node(-1);
        Node* temp = head;
        Node* prev = start;

        unordered_map<Node*, int> nodes;
        vector<Node*> new_nodes;
        vector<Node*> old_nodes;
        
        int i = 0;
        while (temp) {
            nodes[temp] = i;
            old_nodes.push_back(temp);

            Node* curr = new Node(temp->val);
            new_nodes.push_back(curr);

            prev->next = curr;
            prev = prev->next;

            temp = temp->next;
            i++;
        }

        Node* curr = start->next;
        for (int idx = 0; idx < i; idx++) {
            if (old_nodes[idx]->random) new_nodes[idx]->random = new_nodes[nodes[old_nodes[idx]->random]];
        }

        return start->next;
    }
};
