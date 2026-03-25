class Solution {
public:
    bool check(vector<int>& nums) {
        int num_count = nums.size();

        bool sorted = true;
        int break_idx;
        for (int i = 0; i < num_count - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                sorted = false;
                break_idx = i + 1;
                break;
            }
        }

        if (sorted) {
            return true;
        }

        for (int i = 0; i < num_count - 1; i++) {
            if (nums[break_idx] > nums[(break_idx + 1) % num_count]) {
                return false;
            }
            break_idx = (break_idx + 1) % num_count;
        }

        return true;
    }
};
