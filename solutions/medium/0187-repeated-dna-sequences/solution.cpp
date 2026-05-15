class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int count_A, count_T, count_C, count_G;
        vector<string> res;
        int len = s.size();

        if (len <= 10) {
            return res;
        }

        unordered_set<string> seen;
        unordered_set<string> added;

        // A = 0, T = 1, C = 2, G = 3
        string temp = s.substr(0, 10);

        seen.insert(temp);

        int left = 0;
        int right = 9;

        while (right < len) {
            char pre = s[left];
            char post = s[right];

            left++;
            right++;

            temp = s.substr(left, 10);
            cout << temp << endl;
            if (seen.contains(temp) && !added.contains(temp)) {
                res.push_back(temp);
                added.insert(temp);
            }
            else {
                seen.insert(temp);
            }
        }

        return res;
    }
};
