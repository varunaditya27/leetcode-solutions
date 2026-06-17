class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x == y) {
            if (target == x || target == 0) return true;
            else return false;
        }

        if (x + y == target) return true;
        if (x + y < target) return false;

        unordered_set<int> possibilities;
        int mx = max(x,y);
        int mn = 0;

        int large = max(x,y);
        int small = min(x,y);

        possibilities.insert(0);
        possibilities.insert(x);
        possibilities.insert(y);

        while (true) {
            possibilities.insert(mx);
            possibilities.insert(mn);
            possibilities.insert(mx + mn);

            int transfer_capacity = small - mn;
            int transferred = min(mx, transfer_capacity);
            mn = mn + transferred;
            mx = mx - transferred;

            possibilities.insert(mx);
            possibilities.insert(mn);
            possibilities.insert(mx + mn);

            if (mx == 0) {
                if (mn != small) mx = large;
                else break;
            }
            if (mn == small) mn = 0;
        }

        return possibilities.contains(target);
    }
};
