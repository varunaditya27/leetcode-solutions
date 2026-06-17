class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int len = s.size();
        int idx;
        char ch;
        long long res = 0;
        
        for (int i = 0; i < len; i++) {
            //forward
            long long forwardCost = 0;
            ch = s[i];
            idx = ch - 'a';
            while (ch != t[i]) {
                forwardCost += (nextCost[idx] * 1LL);
                idx = (idx + 1) % 26;
                ch = idx + 'a';
            }

            //backward
            long long backwardCost = 0;
            ch = s[i];
            idx = ch - 'a';
            while (ch != t[i]) {
                backwardCost += (previousCost[idx] * 1LL);
                idx = (idx - 1 + 26) % 26;
                ch = idx + 'a';
            }

            res += min(forwardCost, backwardCost);
        }

        return res;
    }
};
