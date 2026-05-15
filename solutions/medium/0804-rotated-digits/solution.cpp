class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int digitCount;
            int num = i;

            if (num < 10) {
                digitCount = 1;
            }

            else if (num < 100) {
                digitCount = 2;
            }

            else if (num < 1000) {
                digitCount = 3;
            }

            else if (num < 10000) {
                digitCount = 4;
            }

            else {
                digitCount = 5;
            }

            int validCount = 0;
            int dependentCount = 0;
            while (num != 0) {
                int rem = num % 10;
                if (rem == 2 || rem == 5 || rem == 6 || rem == 9) {
                    validCount++;
                }
                else if (rem == 0 || rem == 1 || rem == 8) {
                    dependentCount++;
                }
                num = num / 10;
            }

            if (validCount == digitCount) {
                res++;
            }
            else if (validCount != 0 && validCount + dependentCount == digitCount) {
                res++;
            }
        }

        return res;
    }
};
