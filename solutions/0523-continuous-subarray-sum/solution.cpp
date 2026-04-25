class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 1) {
            return false;
        }

        vector<int> prefix_sum(len + 1, 0);
        unordered_set<int> seen_modulo;
        int mod;
        int prev_mod = 0;


        for (int i = 1; i <= len; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
            mod = prefix_sum[i] % k;

            if (seen_modulo.contains(mod)) {
                return true;
            }

            seen_modulo.insert(prev_mod);
            prev_mod = mod;
        }

        return false;
    }
};
