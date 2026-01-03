class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> freq;

        int left = 0;
        int res = INT_MAX;
        int sum = 0;

        for (int right = 0; right < len; right++) {
            if (freq[nums[right]] == 0) {
                sum += nums[right];
            }
            freq[nums[right]]++;
            
            while (sum >= k && left <= right) {
                res = min(res, right - left + 1);
                
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    sum -= nums[left];
                }
                left++;
            }
        }

        if (res != INT_MAX) {
            return res;
        }
        
        return -1;
    }
};
