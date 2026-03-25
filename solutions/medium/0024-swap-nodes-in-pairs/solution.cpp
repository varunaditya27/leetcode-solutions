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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);

        ListNode* next = temp->next;
        ListNode* prev = dummy;

        while (temp != nullptr) {
            if (temp->next == nullptr) {
                break;
            }
            else {
                prev->next = next;
                temp->next = next->next;
                next->next = temp;
                
                if (temp == nullptr || temp->next == nullptr) {
                    break;
                }

                prev = temp;
                temp = prev->next;
                next = temp->next;
            }
        }

        ListNode* new_head = dummy->next;
        delete(dummy);

        return new_head;
    }
};
