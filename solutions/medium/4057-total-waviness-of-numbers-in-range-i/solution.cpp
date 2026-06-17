class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for (int num = num1; num <= num2; num++) {
            string str = to_string(num);
            int len = str.size();

            if (len < 3) continue;
            else {
                for (int i = 1; i < len -1; i++) {
                    if (str[i] - '0' > str[i - 1] - '0' && str[i] - '0' > str[i + 1] - '0') res++;
                    else if (str[i] - '0' < str[i - 1] - '0' && str[i] - '0' < str[i + 1] - '0') res++;
                }
            }
        }

        return res;
    }
};
