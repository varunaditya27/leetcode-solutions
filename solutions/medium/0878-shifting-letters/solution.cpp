class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int len = s.size();
        int shift = 0;

        for (int i = len - 1; i >= 0; i--) {
            shift = (shift + shifts[i])%26;
            s[i] = 'a' + ((s[i] - 'a' + shift) % 26);
        }

        return s;
    }
};
