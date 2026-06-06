class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0};

        vector<int> left_sum(n + 1, 0);
        vector<int> right_sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            left_sum[i + 1] = left_sum[i] + nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            right_sum[i] = right_sum[i + 1] + nums[i];
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = abs(left_sum[i] - right_sum[i + 1]);
        }

        return res;
    }
};
