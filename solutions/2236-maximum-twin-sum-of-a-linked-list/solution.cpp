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
    int pairSum(ListNode* head) {
        if (!head->next->next) return head->val + head->next->val;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        ListNode* nxt = slow->next;

        while (curr) {
            nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        slow->next = prev;

        ListNode* first = head;
        ListNode* second = slow->next;

        int res = 0;
        while (second) {
            res = max(res, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return res;
    }
};
