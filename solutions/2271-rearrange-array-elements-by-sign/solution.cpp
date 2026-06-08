class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;

        int positive = 0;
        int negative = 0;

        while (positive < len || negative < len) {
            while (positive < len && nums[positive] < 0) positive++;
            while (negative < len && nums[negative] > 0) negative++;

            if (positive < len) res.push_back(nums[positive]);
            if (negative < len) res.push_back(nums[negative]);

            positive++;
            negative++;
        }

        return res;
    }
};
