#include <set>
#include <vector>
#include <numeric>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<int> unique_nums(nums.begin(), nums.end());
        set<vector<int>> unique_triplets;

        unordered_map<int, int> freq_table;
        for (int num : nums) {
            freq_table[num]++;
        }

        vector<int> temp;

        int vec_length = nums.size();

        for (int i = 0; i <= vec_length - 3; i++) {
            for (int j = i + 1; j <= vec_length - 2; j++) {
                int sum = nums[i] + nums[j];
                if (unique_nums.contains(-sum)) {
                    if ((-sum == nums[i] && -sum == nums[j] && freq_table[-sum] >= 3) || (-sum == nums[i] && -sum != nums[j] && freq_table[-sum] >= 2) || (-sum == nums[j] && -sum != nums[i] && freq_table[-sum] >= 2) || (-sum != nums[i] && -sum != nums[j] && freq_table[-sum] >= 1)) {
                        temp = {nums[i], nums[j], -sum};
                        sort(temp.begin(), temp.end());

                        unique_triplets.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> result(unique_triplets.begin(), unique_triplets.end());
        return result;
    }
};
