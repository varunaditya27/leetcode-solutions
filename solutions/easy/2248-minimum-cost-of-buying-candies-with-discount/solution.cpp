class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());
        int len = cost.size();
        int first, second, free;
        int res = 0;

        if (len == 1) {
            return cost[0];
        }

        else if (len == 2) {
            return cost[0] + cost[1];
        }

        int mod = len % 3;

        for (int i = 0; i < len - mod; i += 3) {
            res += cost[i];
            res += cost[i + 1];
        }

        if (mod == 1) {
            res += cost[len - 1];
        }

        else if (mod == 2) {
            res += cost[len - 1];
            res += cost[len - 2];
        }

        return res;
    }
};
