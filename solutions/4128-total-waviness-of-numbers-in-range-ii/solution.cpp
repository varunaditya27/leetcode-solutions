class Solution {
public:
    long long cnt[17][11][11][2][2];
    long long sum[17][11][11][2][2];
    bool vis[17][11][11][2][2];
    vector<int> digits;

    pair<long long, long long> solve(int pos, int prev2, int prev1, int tight, int started) {
        if (pos == (int)digits.size()) return {1, 0};

        if (vis[pos][prev2][prev1][tight][started]) return {cnt[pos][prev2][prev1][tight][started], sum[pos][prev2][prev1][tight][started]};
        vis[pos][prev2][prev1][tight][started] = true;

        long long ways = 0, ans = 0;
        int lim = tight ? digits[pos] : 9;

        for (int d = 0; d <= lim; d++) {
            int ntight = tight && (d == lim);
            int nstarted = started || (d != 0);

            int add = 0;
            if (started && prev2 != 10 && prev1 != 10) {
                if (prev1 > prev2 && prev1 > d) add = 1;
                else if (prev1 < prev2 && prev1 < d) add = 1;
            }

            int nprev2, nprev1;
            if (!nstarted) {
                nprev2 = 10;
                nprev1 = 10;
            } else if (!started) {
                nprev2 = 10;
                nprev1 = d;
            } else {
                nprev2 = prev1;
                nprev1 = d;
            }

            auto temp = solve(pos + 1, nprev2, nprev1, ntight, nstarted);
            ways += temp.first;
            ans += temp.second + 1LL * add * temp.first;
        }

        cnt[pos][prev2][prev1][tight][started] = ways;
        sum[pos][prev2][prev1][tight][started] = ans;

        return {ways, ans};
    }

    long long calc(long long x) {
        if (x < 0) return 0;

        digits.clear();
        if (x == 0) digits.push_back(0);
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        memset(vis, 0, sizeof(vis));
        return solve(0, 10, 10, 1, 0).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};
