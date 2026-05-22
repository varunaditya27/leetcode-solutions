class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixSet;
        int res = 0;

        for (int num1: arr1) {
            while (num1 > 0) {
                prefixSet.insert(num1);
                num1 /= 10;
            }
        }

        for (int num2: arr2) {
            while (num2 > 0) {
                if (prefixSet.count(num2) != 0) {
                    res = max(res, (int)to_string(num2).size());
                }
                num2 /= 10;
            }
        }

        return res;
    }
};
