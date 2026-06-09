class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long res = 0;
        int min = nums[0];
        int max = nums[0];
        
        int len = nums.size();
        
        for (int i = 0;  i < len;  i++) {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }
        
        return (long long)(max - min) * (long long)k;
    }
};
