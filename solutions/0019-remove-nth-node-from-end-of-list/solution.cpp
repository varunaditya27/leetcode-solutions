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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;

        int counter = 0;

        while (temp != nullptr) {
            temp = temp->next;
            counter++;
        }

        if (n == counter) {
            temp = head->next;
            return temp;
        }

        int target = counter - n + 1;
        counter = 1;
        temp = head;

        while (counter < target - 1) {
            temp = temp->next;
            counter++;
        }

        temp->next = temp->next->next;

        return head;
    }
};
