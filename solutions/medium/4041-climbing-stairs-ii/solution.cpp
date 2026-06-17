class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        int jump1, jump2, jump3;

        dp[1] = costs[0] + 1; if (n == 1) return dp[1];
        dp[2] = min(costs[1] + 4, dp[1] + costs[1] + 1); if (n == 2) return dp[2];
        dp[3] = min(min(costs[2] + 9, dp[2] + costs[2] + 1), dp[1] + costs[2] + 4); if (n == 3) return dp[3];

        for (int i = 4; i <= n; i++) {
            jump1 = dp[i - 1] + costs[i - 1] + 1;
            jump2 = dp[i - 2] + costs[i - 1] + 4;
            jump3 = dp[i - 3] + costs[i - 1] + 9;

            dp[i] = min(min(jump1, jump2), jump3);
        }

        return dp[n];
    }
};
