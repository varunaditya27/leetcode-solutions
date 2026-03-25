class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<int> bool_arr(n, 1);
        bool_arr[0] = 0;
        bool_arr[1] = 0;
        
        for (int i = 2; i < n; i++) {
            for (int j = 2 * i; j < n; j += i) {
                bool_arr[j] = 0;
            }
        }
        
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (bool_arr[i] == 1)
                count++;
        }

        return count;
    }
};
