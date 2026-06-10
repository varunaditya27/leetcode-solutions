class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
    
        int len = intervals.size();
        if (len == 1) return intervals;

        vector<int> prev = intervals[0];
        for (int i = 1; i < len; i++) {
            vector<int> curr = intervals[i];

            int prev_start = prev[0];
            int prev_end = prev[1];

            int curr_start = curr[0];
            int curr_end = curr[1];

            if (curr_start > prev_end) {
                res.push_back(prev);
                prev = curr;
            }
            else {
                if (curr_end > prev_end) {
                    prev[1] = curr_end;
                }
            }
        }

        int n = res.size();
        if (n == 0 || res[n - 1] != prev) res.push_back(prev);
        return res;
    }
};
