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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        if (k % n == 0) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < (k % n); i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* new_head = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return new_head;
    }
};
