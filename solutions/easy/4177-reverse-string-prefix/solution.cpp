class Solution {
public:
    string reversePrefix(string s, int k) {
        string res = s;
        for (int i = 0; i < k; i++) {
            res[k - 1 - i] = s[i];
        }

        return res;
    }
};
