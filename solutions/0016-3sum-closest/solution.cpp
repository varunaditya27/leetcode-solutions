class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int sum;
        int res;
        int min_diff = INT_MAX;
        int diff;

        for (int a = 0; a < len - 2; a++) {
            for (int b = a + 1; b < len - 1; b++) {
                for (int c = b + 1; c < len; c++) {
                    sum = nums[a] + nums[b] + nums[c];
                    diff = abs(target - sum);
                    if (diff < min_diff) {
                        res = sum;
                        min_diff = diff;
                    }
                }
            }
        }

        return res;
    }
};
