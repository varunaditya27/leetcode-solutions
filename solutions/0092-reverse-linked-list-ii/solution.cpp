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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr || left == right) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        int pos = 1;

        while (pos < left) {
            next = curr->next;
            prev = curr;
            curr = curr->next;
            pos++;
        }

        ListNode* left_boundary = prev;
        ListNode* left_node = curr;
        prev = nullptr;

        while (pos <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }
        
        ListNode* right_node = prev;
        ListNode* right_boundary = curr;

        if (left_boundary != nullptr) {
            left_boundary->next = right_node;
        }
        else {
            head = right_node;
        }

        left_node->next = right_boundary;

        return head;
    }
};
