#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;

        int counter = 0;
        vector<ListNode*> node_addresses;

        while (temp != nullptr) {
            node_addresses.push_back(temp);
            temp = temp->next;
            counter++;
        }

        if (n == counter) {
            temp = head->next;
            delete head;
            return temp;
        }

        ListNode* target = node_addresses[counter - n];
        ListNode* prev = node_addresses[counter - n - 1];

        prev->next = target->next;

        delete target;

        return head;
    }
};
