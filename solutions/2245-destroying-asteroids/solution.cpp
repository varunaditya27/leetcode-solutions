class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int len = asteroids.size();

        long long sum = mass;
        for (int i = 0; i < len; i++) {
            if (sum < asteroids[i]) {
                return false;
            }
            sum += asteroids[i];
        }

        return true;
    }
};
