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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }
        if (list1 && !list2) {
            return list1;
        }
        if (list2 && !list1) {
            return list2;
        }

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* res;

        if (curr1->val < curr2->val) {
            res = curr1;
            curr1 = curr1->next;
        }
        else {
            res = curr2;
            curr2 = curr2->next;
        }
        
        ListNode* curr = res;

        while (curr1 || curr2) {
            if (curr1 && curr2) {
                if (curr1->val < curr2->val) {
                    curr->next = curr1;
                    curr = curr1;
                    curr1 = curr1->next;
                }
                else {
                    curr->next = curr2;
                    curr = curr2;
                    curr2 = curr2->next;
                }
            }
            else if (!curr2) {
                curr->next = curr1;
                curr = curr1;
                curr1 = curr1->next;
            }
            else {
                curr->next = curr2;
                curr = curr2;
                curr2 = curr2->next;
            }
        }

        return res;
    }
};
