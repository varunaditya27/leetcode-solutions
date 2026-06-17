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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();

        if (len == 0) return nullptr;
        if (len == 1) return lists[0];

        int flag = 0;
        ListNode res(0);
        ListNode* dummy = &res;
        ListNode* temp;
        dummy->next = temp;

        vector<int> completed(len, 0);

        int min_idx;
        int min_val;

        ListNode* curr;
        ListNode* least;

        while (flag < len) {
            min_idx = -1;
            min_val = INT_MAX;

            ListNode* temp;

            for (int i = 0; i < len; i++) {
                curr = lists[i];

                if (curr == nullptr && completed[i] == 0) {
                    completed[i] = 1;
                    flag++;
                }
                if (curr != nullptr) {
                    if (curr->val < min_val) {
                        least = lists[i];
                        min_idx = i;
                        min_val = curr->val;

                        //cout << i << " -> " << curr->val << endl;
                    }
                }
            }
            if (min_idx == -1) break;

            if (lists[min_idx]) {
                cout << lists[min_idx]->val << " ";
                dummy->next = lists[min_idx];
                dummy = dummy->next;
                lists[min_idx] = lists[min_idx]->next;
            }

        }

        return res.next;
    }
};
