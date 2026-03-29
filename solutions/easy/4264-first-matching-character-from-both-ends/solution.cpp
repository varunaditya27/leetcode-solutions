class Solution {
public:
    int firstMatchingIndex(string s) {
        int len = s.size();
        if (len == 1) {
            return 0;
        }
        
        int left = 0;
        int right = len - 1;

        while (left <= right) {
            if (s[left] == s[right]) {
                return left;
            }
            left++;
            right--;
        }

        return -1;
    }
};
