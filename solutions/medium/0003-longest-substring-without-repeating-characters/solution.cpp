class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_len = s.length();
        if (str_len == 0 || str_len == 1) {
            return str_len;
        }

        int left = 0;
        int result = 0;
        int window_size;

        unordered_set<char> seen_letters;

        for (int right = 0; right < str_len; right++) {
            int new_letter_count = seen_letters.count(s[right]);
            while (new_letter_count > 0) {
                if (s[left] == s[right]) {
                    new_letter_count--;
                }
                seen_letters.erase(s[left]);
                left++;
            }
            seen_letters.insert(s[right]);
            int window_size = right - left + 1;
            result = max(result, window_size);
        }

        return result;
    }
};
