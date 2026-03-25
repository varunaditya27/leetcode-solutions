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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* prev = dummy;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                int n = curr->val;
                while (curr->val == n) {
                    if (curr->next == nullptr) {
                        prev->next = nullptr;
                        curr = nullptr;
                        break;
                    }
                    curr = curr->next;
                }
                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
