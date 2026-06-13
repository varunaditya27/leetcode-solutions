class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();

        int res = 0;
        int curr = 0;

        unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) curr++;
            else curr--;

            if (map.contains(curr)) res = max(res, i - map[curr]);
            else map[curr] = i;
        }

        return res;
    }
};
