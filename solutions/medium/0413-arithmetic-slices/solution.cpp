class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        int dp = 0;
        int res = 0;

        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
            }
            else {
                dp = 0;
            }
            res += dp;
        }

        return res;
    }
};
