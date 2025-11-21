class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow_ptr = 0;

        if (nums.size() == 1) {
            return 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[slow_ptr]) {
                slow_ptr++;
                nums[slow_ptr] = nums[i];
            }
        }

        return slow_ptr + 1;
    }
};
