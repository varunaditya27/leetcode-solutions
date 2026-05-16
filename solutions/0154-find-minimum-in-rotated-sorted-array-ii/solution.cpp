class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for (int num: nums) {
            res = min(res, num);
        }
        return res;
    }
};
