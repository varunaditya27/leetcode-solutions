class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> res;

        for (int i = 0; i < m; i++) {
            int start = l[i];
            int end = r[i];
            int len = end - start + 1;

            if (len == 2) {
                res.push_back(true);
                continue;
            }

            int flag = 0;

            vector<int> temp;
            for (int k = start; k <= end; k++) {
                temp.push_back(nums[k]);
            }
            sort(temp.begin(), temp.end());

            for (int x = 0; x < len - 2; x++) {
                if (temp[x + 1] - temp[x] !=  temp[x + 2] - temp[x + 1]) {
                    flag = 1;
                    res.push_back(false);
                    break;
                }
            }

            if (flag == 0) {
                res.push_back(true);
            }
        }

        return res;
    }
};
