class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = nums.size();
        int res = 0;

        unordered_map<int, int> map;
        map[0] = 1;

        int running_sum = 0;

        for (int i = 0; i < len; i++) {
            running_sum += nums[i];
            if (map.contains(running_sum - goal)) {
                res += map[running_sum - goal];
            }
            map[running_sum]++;
        }

        return res;
    }
};
