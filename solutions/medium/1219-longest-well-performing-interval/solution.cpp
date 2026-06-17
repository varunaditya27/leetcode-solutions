class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0;
        int len = hours.size();

        multimap<int, int> map;
        map.insert({0,0});
        
        vector<int> prefix(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            if (hours[i - 1] > 8) prefix[i] = 1;
            else prefix[i] = -1;

            prefix[i] += prefix[i - 1];
            map.insert({prefix[i], i});
        }

        for (int i = 1; i <= len; i++) {
            if (prefix[i] > 0) res = max(res, i);
            else {
                if (map.contains(prefix[i] - 1)) res = max(res, i - map.find(prefix[i] - 1)->second);
            }
        }

        return res;
    }
};
