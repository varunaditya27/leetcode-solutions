class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        int result;

        for (int num : nums) {
            if (seen.count(num) == 0) {
                seen.insert(num);
            }
            else {
                result = num;
                break;
            }
        }

        return result;
    }
};
