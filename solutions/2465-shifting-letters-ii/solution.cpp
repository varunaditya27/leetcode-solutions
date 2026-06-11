class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = shifts.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < len; i++) {
            right = max(right, shifts[i][1]);
        }

        int n = right - left + 1;
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < len; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction == 1) {
                prefix[start] = (prefix[start] + 1 + 26) % 26;
                prefix[end + 1] = (prefix[end + 1] - 1 + 26) % 26;
            }
            else {
                prefix[start] = (prefix[start] - 1 + 26) % 26;
                prefix[end + 1] = (prefix[end + 1] + 1 + 26) % 26;
            }
        }

        int add = 0;
        for (int i = 0; i < n; i++) {
            add += prefix[i];
            s[i] = 'a' + ((s[i] - 'a' + add) % 26);
        }

        return s;
    }
};
