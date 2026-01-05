class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq;

        int len = nums.size();
        if (len == 1) {
            return;
        }

        for (int i = 0; i < len; i++) {
            freq[nums[i]]++;
        }

        for (int i = 0; i < freq[0]; i++) {
            nums[i] = 0;
        }

        for (int i = freq[0]; i < freq[0] + freq[1]; i++) {
            nums[i] = 1;
        }

        for (int i = freq[0] + freq[1]; i < freq[0] + freq[1] + freq[2]; i++) {
            nums[i] = 2;
        }

        return;
    }
};
