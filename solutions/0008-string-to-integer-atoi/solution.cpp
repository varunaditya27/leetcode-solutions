class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        int len = s.size();
        long long res = 0;

        while (s[start] == ' ') {
            start++;
        }

        bool positive = true;
        if (s[start] == '-') {
            positive = false;
        }

        if (s[start] == '+' || !positive) {
            start++;
        }

        while (s[start] == '0') {
            start++;
        }

        while (start < len && isdigit(s[start])) {
            res *= 10;
            res += (s[start] - '0');
        
            if (positive && res > (long long)INT_MAX) {
                return INT_MAX;
            }
            else if (!positive && res > (long long)INT_MAX + 1) {
                return INT_MIN;
            }

            start++;
        }

        if (positive) {
            return res;
        }
        
        return res * -1;
    }
};
