class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int len = nums.size();
        int logn = 32 - __builtin_clz(len);

        vector<vector<int>> stMax(len, vector<int>(logn));
        vector<vector<int>> stMin(len, vector<int>(logn));

        for (int i = 0; i < len; i++) {
            stMax[i][0] = nums[i];
            stMin[i][0] = nums[i];
        }

        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= len; i++) {
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };

        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };

        priority_queue<tuple<int, int, int>> pq;

        for (int l = 0; l < len; l++) {
            pq.emplace(queryMax(l, len - 1) - queryMin(l, len - 1), l, len - 1);
        }

        long long res = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            res += val;

            if (r > l) {
                pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
            }
        }

        return res;
    }
};
