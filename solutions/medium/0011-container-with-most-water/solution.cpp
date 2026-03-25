#include <algorithm>

class Solution {
public:
    long long int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int area;
        int result = 0;

        while (left < right) {
            area = min(height[left], height[right]) * (right - left);
            result = max(area, result);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return result;
    }
};
