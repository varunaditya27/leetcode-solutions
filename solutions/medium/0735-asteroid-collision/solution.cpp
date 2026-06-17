class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int len = asteroids.size();
        int curr;

        for (int i = 0; i < len; i++) {
            curr = asteroids[i];
            if (curr > 0 || res.empty() || res.back() < 0) {
                res.push_back(curr);
            }
            else {
                while (!res.empty() && (res.back() > 0 && res.back() < -curr)) {
                    res.pop_back();
                }

                if (res.empty()) res.push_back(curr);
                else {
                    if (res.back() == -curr) res.pop_back();
                    else if (res.back() < 0) res.push_back(curr);
                }
            }
        }

        return res;
    }
};
