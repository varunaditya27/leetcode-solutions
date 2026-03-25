/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        if (head->next == head) {
            return head;
        }

        int flag = 0;
        ListNode* fast = head;
        ListNode* slow = head;

        unordered_set<ListNode*> seen;

        while (fast->next != nullptr) {
            if (seen.count(fast) == 1) {
                return fast;
            }
            seen.insert(fast);
            fast = fast->next;       
        }

        return nullptr;
    }
};
