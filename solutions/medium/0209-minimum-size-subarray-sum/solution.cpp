class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int init_sum = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size();
        int res = len;

        if (init_sum < target) {
            return 0;
        }

        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int i = 1; i <= len; i++) {
            prefix_sum.push_back(prefix_sum[i - 1] + nums[i - 1]);
        }

        int left = 1, right = 1;

        while (right <= len) {
            init_sum = prefix_sum[right] - prefix_sum[left - 1];
            if (init_sum < target) {
                right++;
            }
            else {
                while (init_sum >= target) {
                    res = min(res, right - left + 1);
                    cout << "Left = " << left << " Right = " << right << " Sum = " << init_sum << " Ans = " << res << endl;
                    left++;
                    init_sum = prefix_sum[right] - prefix_sum[left - 1];
                }
            }
        }

        return res;
    }
};
