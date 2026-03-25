#include <queue>

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }

        queue<int> less_values;
        queue<int> greater_values;
        
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                less_values.push(curr->val);
            } else {
                greater_values.push(curr->val);
            }
            curr = curr->next;
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* builder = dummy;
        
        while (!less_values.empty()) {
            builder->next = new ListNode(less_values.front());
            less_values.pop();
            builder = builder->next;
        }
        
        while (!greater_values.empty()) {
            builder->next = new ListNode(greater_values.front());
            greater_values.pop();
            builder = builder->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

