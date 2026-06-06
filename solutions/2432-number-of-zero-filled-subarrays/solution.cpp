class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int len = nums.size();
        long long res = 0;
        long long dp = 0;

        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
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
