class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> prefix(1003, 0);
        int len = trips.size();

        int from, to, numPassengers;

        for (int i = 0; i < len; i++) {
            numPassengers = trips[i][0];
            from = trips[i][1];
            to = trips[i][2];

            prefix[from + 1] += numPassengers;
            prefix[to + 1] -= numPassengers;
        }

        for (int i = 1; i < 1001; i++) {
            prefix[i] += prefix[i - 1];
            if (prefix[i] > capacity) return false;
        }

        return true;
    }
};
