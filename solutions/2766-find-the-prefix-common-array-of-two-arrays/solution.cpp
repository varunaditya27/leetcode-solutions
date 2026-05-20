class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> res(len, 0);
        unordered_set<int> seenA;
        unordered_set<int> seenB;

        for (int i = 0; i < len; i++) {
            if (i != 0) {
                res[i] += res[i - 1];
            }
            if (A[i] == B[i]) {
                res[i]++;
            }
            if (seenA.contains(B[i])) {
                res[i]++;
            }
            if (seenB.contains(A[i])) {
                res[i]++;
            }
            seenA.insert(A[i]);
            seenB.insert(B[i]);
        }

        return res;
    }
};
