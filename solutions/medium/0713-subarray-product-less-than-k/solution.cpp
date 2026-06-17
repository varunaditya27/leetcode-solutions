class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int left = 0;
        int len;
        long long prod = 1;

        for (int right = 0; right < n; right++) {
            prod *= nums[right];

            while (prod >= k && left <= right) {
                prod /= nums[left];
                left++;
            }

            len = right - left + 1;
            res += len;
        }

        return res;
    }
};
