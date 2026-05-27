#define IMPOSSIBLE -1 

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> letters(52);
        int len = word.length();
        int res = 0;

        for (char letter: word) {
            if (letter >= 97 && letter <= 122) {
                if (letters[letter - 'a' + 26] == 0) {
                    letters[letter - 'a'] = 1;
                }
                else {
                    letters[letter - 'a' + 26] = IMPOSSIBLE;
                    letters[letter - 'a'] = IMPOSSIBLE;
                }
            }
            else {
                if (letters[letter - 'A'] == 1) {
                    letters[letter - 'A' + 26] = 1;
                }
                else {
                    letters[letter - 'A' + 26] = IMPOSSIBLE;
                }
            }
        }

        for (int i = 26; i < 52; i++) {
            if (letters[i] == 1) {
                res++;
            }
        }

        return res;
    }
};
