class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int len = bookings.size();
        vector<int> res(n + 1, 0);

        for (int i = 0; i < len; i++) {
            int start = bookings[i][0];
            int end = bookings[i][1];
            int seats = bookings[i][2];

            res[start - 1] += seats;
            res[end] -= seats;
        }

        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }

        res.pop_back();
        return res;
    }
};
