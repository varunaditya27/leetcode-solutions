class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            int bufA = a[1] - a[0];
            int bufB = b[1] - b[0];
            if (bufA != bufB) return bufA > bufB;
            return a[1] > b[1];
        });

        int res = 0, energy = 0;
        for (auto t : tasks) {
            if (energy < t[1]) {
                res += t[1] - energy;
                energy = t[1];
            }
            energy -= t[0];
        }
        return res;
    }
};
