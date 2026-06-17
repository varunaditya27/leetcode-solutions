class Solution {
public:
    int digitSum(int num) {
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int num: nums) {
            res = min(res, digitSum(num));
        }

        return res;
    }
};
