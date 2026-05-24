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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* ref = head;
        ListNode* curr;

        while (ref && ref->next) {
            if (ref->val <= ref->next->val) {
                ref = ref->next;
                continue;
            }

            curr = ref->next;
            ref->next = curr->next;

            if (curr->val < head->val) {
                curr->next = head;
                head = curr;
            }
            else {
                ListNode* temp = head;
                while (temp->next && temp->next->val <= curr->val) {
                    temp = temp->next;
                }

                curr->next = temp->next;
                temp->next = curr;
            }
        }

        return head;
    }
};
