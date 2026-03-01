class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int len = nums.size();
        int zero_count = 0;
        int res = 0;

        while (right < len) {
            if (nums[right] == 0) {
                zero_count++;

                if (zero_count > k) {
                    res = max(res, right - left);
                    while (left < len && nums[left] != 0) {
                        left++;
                    }
                    left++;
                    zero_count--;
                }

                right++;
            }
            else {
                right++;
            }
        }

        res = max(res, right - left);
        return res;
    }
};
