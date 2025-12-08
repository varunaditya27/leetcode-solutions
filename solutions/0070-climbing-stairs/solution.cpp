long long int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    long long int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long nCr (int n, int r) {
    if (r > (n - r)) {
        r = n - r;
    }
    
    long long result = 1;

    for (int i = 1; i <= r; i++) {
        result = result * (n - r + i) / i;
    }

    return result;
}

class Solution {
public:
    int climbStairs(int n) {
        long long int ans = 1; // base case of all 1s

        if (n == 1)
            return ans;

        int max_num_of_2s = n/2;

        for (int i = 1; i <= max_num_of_2s; i++) {
            int num_of_1s = n - (2*i);
            ans += nCr(n - i, i);
        }

        return ans;
    }
};
