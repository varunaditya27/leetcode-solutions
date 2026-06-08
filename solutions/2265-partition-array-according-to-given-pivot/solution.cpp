class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        deque<int> rem;

        int len = nums.size();
        int count = 0;

        for (int i = 0; i < len; i++) {
            if (nums[i] < pivot) {
                res.push_back(nums[i]);
            }

            else if (nums[i] == pivot) {
                count++;
            }

            else {
                rem.push_back(nums[i]);
            }
        }

        for (int i = 0; i < count; i++) {
            res.push_back(pivot);
        }

        while (!rem.empty()) {
            res.push_back(rem.front());
            rem.pop_front();
        }

        return res;
    }
};
