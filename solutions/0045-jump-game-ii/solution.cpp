class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;

        int max_limit = 0;
        int jumps = 0;
        int curr_limit = 0;

        for (int i = 0; i < len - 1; i++) {
            max_limit = max(max_limit, i + nums[i]);

            if (i == curr_limit) {
                jumps++;
                curr_limit = max_limit;
            }
        }

        return jumps;
    }
};
