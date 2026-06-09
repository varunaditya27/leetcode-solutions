/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }

        vector<ListNode*> nodes;
        temp = head;

        int idx = 0;
        while (idx < count) {
            nodes.push_back(temp);
            temp = temp->next;
            idx++;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        int i = 0;
        int track = count;
        while (track > 0) {
            curr->next = nodes[i];
            curr = curr->next;
            cout << curr->val << " ";
            track--;
            
            if (track > 0) {
                curr->next = nodes[count - i - 1];
                curr = curr->next;
                cout << curr->val << " ";
                track--;
            }

            i++;
        }

        curr->next = nullptr;
    }
};
