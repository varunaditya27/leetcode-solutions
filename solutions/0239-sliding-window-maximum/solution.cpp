class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap;
        vector<int> res;

        int len = nums.size();

        for (int i = 0; i < len; i++) {
            heap.push({nums[i], i});

            while (heap.top().second < i - k + 1) {
                heap.pop();
            }

            if (i >= k - 1) {
                res.push_back(heap.top().first);
            }
        }
        return res;
    }
};
