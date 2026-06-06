class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int max_bulb_count = (n + 3 - 1)/3; //determine bulb count later
        int bulb_count = (brightness + 3 - 1)/3;
        
        int interval_count = intervals.size();
        int interval_len;
        long long res = 0;
        int max_end_time = INT_MIN;
        
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < interval_count; i++) {
            int start_time = intervals[i][0];
            int end_time = intervals[i][1];
            int flag = start_time > max_end_time ? 1 : 0;

            if (end_time < max_end_time) continue;
            else start_time = max(start_time, max_end_time);

            interval_len = end_time - start_time + flag;

            res += (long long)interval_len * (long long)bulb_count;
            max_end_time = max(end_time, max_end_time);
        }

        return res;
    }
};
