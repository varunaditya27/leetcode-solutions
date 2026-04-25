class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);

        vector<int> left_prefix(len + 2, 1);
        vector<int> right_prefix(len + 2, 1);

        for (int i = 1; i <= len; i++) {
            left_prefix[i] = left_prefix[i - 1] * nums[i -1];
            cout << left_prefix[i] << " = " << left_prefix[i - 1] << " * " << nums[i -1] << endl;
        }
        cout << endl << endl;
        for (int i = len; i > 0; i--) {
            right_prefix[i] = right_prefix[i + 1] * nums[i - 1];
            cout << right_prefix[i] << " = " << right_prefix[i + 1] << " * " << nums[i -1] << endl;
        }
        cout << endl << endl;
        for (int i = 0; i < len; i++) {
            res[i] = left_prefix[i] * right_prefix[i + 2];
            cout << res[i] << " = " << left_prefix[i] << " * " << right_prefix[i + 2] << endl;
        }

        return res;
    }
};
