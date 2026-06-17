class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];

        deque<int> q;
        for (int i = 0; i < len; i++) {
            q.push_back(nums[i]);
        }

        while (!q.empty()) {
            int count = q.size();
            if (count == 1) {
                return q.front();
            }
            for (int i = 0; i < count - 1; i++) {
                q.push_back((q[0] + q[1]) % 10);
                q.pop_front();
            }
            q.pop_front();
        }

        return q.front();
    }
};
