class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int len = prices.size();
        long long res = len;
        long long dp = 0;

        for (int i = 1; i < len; i++) {
            if (prices[i] == prices[i - 1] - 1) {
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
