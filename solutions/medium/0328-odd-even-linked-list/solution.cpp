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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev;
        ListNode* even_curr;

        ListNode* dummy = new ListNode(0);
        even_curr = dummy;

        while (curr != nullptr) {
            even_curr->next = curr->next;

            if (curr->next != nullptr) {
                curr->next = curr->next->next;
                even_curr = even_curr->next;
            }

            even_curr->next = nullptr;
            prev = curr;
            curr = curr->next;
        }

        prev->next = dummy->next;
        return head;
    }
};
