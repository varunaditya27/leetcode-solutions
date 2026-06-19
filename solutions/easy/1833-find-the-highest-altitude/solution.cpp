class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int len = gain.size();
        int running_sum = 0;

        for (int i = 0; i < len; i++) {
            running_sum += gain[i];
            res = max(res, running_sum);
        }

        return res;
    }
};
