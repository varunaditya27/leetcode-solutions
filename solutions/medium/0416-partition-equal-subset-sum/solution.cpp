class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int total_sum = 0;

        for (int i = 0; i < len; i++) {
            total_sum += nums[i];
        }

        if (total_sum % 2 != 0) {
            return false;
        }

        int target = total_sum/2;

        for (int i = 0; i < len; i++) {
            if (nums[i] > target) {
                return false;
            }
        }

        vector<vector<int>> dp(len + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= len; i++) {
            int val = nums[i - 1];
            for (int j = 1; j <= target; j++) {
                if (j == val) {
                    dp[i][j] = 1;
                }
                else if (j > val) {
                    dp[i][j] = dp[i - 1][j - val] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }

            if (dp[i][target] == 1) {
                return true;
            }
        }

        return false;
    }
};
