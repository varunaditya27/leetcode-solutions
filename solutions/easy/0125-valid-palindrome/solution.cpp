#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && isalnum(s[left]) == false) {
                left++;
            }

            if (isdigit(s[left]) == false && islower(s[left]) == false) {
                s[left] = tolower(s[left]);
            }

            while (right > left && isalnum(s[right]) == false) {
                right--;
            }

            if (isdigit(s[right]) == false && islower(s[right]) == false) {
                s[right] = tolower(s[right]);
            }

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
