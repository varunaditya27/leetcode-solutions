class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = 0;
        int max_idx;
        int len = nums.size();
        int i;

        for (i = 1; i < len; i++) {
            if (nums[i] < nums[i - 1]) {
                break;
            }
        }

        if (i == len) {
            return true;
        }

        if (nums[i] > nums[0]) {
            return false;
        }

        for (i += 1; i < len; i++) {
            if (nums[i] > nums[0] || nums[i] < nums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};
