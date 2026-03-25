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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return head;
        }

        ListNode* temp = head->next;
        ListNode* prev = head;

        int prev_val = prev->val;

        while (temp != nullptr) {
            if (temp->val == prev_val) {
                if (temp->next != nullptr) {
                    prev->next = temp->next;
                    temp = temp->next;
                }
                else {
                    prev->next = nullptr;
                    temp = temp-> next;
                }
            }
            else {
                prev = prev->next;
                temp = temp->next;
                prev_val = prev->val;
            }
        }

        return head;
    }
};
