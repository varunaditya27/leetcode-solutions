class Solution {
public:
    string processStr(string s) {
        string res;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
            else if (ch == '*') {
                if (!res.empty()) res.pop_back();
            }
            else if (ch == '#') {
                res += res;
            }
            else if (ch == '%') {
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};
