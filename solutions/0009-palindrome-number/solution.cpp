class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int original = x;
        int rev_num = 0;
        while (x != 0) {
            if (rev_num > (INT_MAX/10) || rev_num < (INT_MIN/10)) {
                return false;
            }
            rev_num *= 10;
            rev_num += (x % 10);
            x /= 10;
        }

        if (original == rev_num) {
            return true;
        }

        return false;
    }
};
