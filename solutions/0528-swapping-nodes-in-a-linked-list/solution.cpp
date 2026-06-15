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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head->next) return head;

        ListNode* temp = head;
        int counter = 0;

        while (temp != nullptr) {
            temp = temp->next;
            counter++;
        }

        int first = min(k, counter - k + 1);
        int second = max(k, counter - k + 1);

        ListNode* prev1 = new ListNode(0, head);
        ListNode* prev2 = nullptr;

        temp = head;
        int i = 1;

        while (i < first) {
            prev1 = temp;
            temp = temp->next;
            i++;
        }

        prev2 = prev1;

        while (i < second) {
            prev2 = temp;
            temp = temp->next;
            i++;
        }

        int swap = prev2->next->val;
        prev2->next->val = prev1->next->val;
        prev1->next->val = swap;

        return head;
    }
};
