class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int len = items.size();
        vector<int> arr(len, 0);
        int i = 0;

        /*for (auto item:items) {
            for (auto item2:items) {
                if (item2[0] % item[0] == 0) {
                     arr[i]++;
                }
            }
            i++;
        }*/

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    arr[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < len; i++) {
            int price = items[i][1];
            int first_copy_val = arr[i];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + first_copy_val);
            }

        }

        for (int j = 1; j <= budget; j++) {
            for (int i = 0; i < len; i++) {
                if (j >= items[i][1]) {
                    dp[j] = max(dp[j], 1 + dp[j - items[i][1]]);
                }
            }
        }
        
        return dp[budget];
    }
};
