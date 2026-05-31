class Solution {
public:
    void helperFunc(vector<int>& nums, int target, int curr, int idx, int n, int& count) {
        if (idx == n) {
            if (target == curr) {
                count++;
            }
            return;
        }

        helperFunc(nums, target, curr + nums[idx], idx + 1, n, count);
        helperFunc(nums, target, curr - nums[idx], idx + 1, n, count);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        int len = nums.size();

        helperFunc(nums, target, 0, 0, len, res);

        return res;
    }
};
