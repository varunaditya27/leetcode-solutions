class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx_map;
        int len = nums.size();
        vector<int> res;


        for (int i = 0; i < len; i++) {
            idx_map[nums[i]] = i;
        }

        for (int i = 0; i < len; i++) {
            auto iter = idx_map.find(target - nums[i]);
            if (iter != idx_map.end()) {
                int idx = iter->second;
                
                if (i != idx) {
                    res = {i, idx};
                    return res;
                }
            }
        }

        return res;
    }
};
