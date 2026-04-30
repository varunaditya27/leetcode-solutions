class Solution {
public:
    bool canJump(vector<int>& nums) {
        deque<int>zero_idx;
        int len = nums.size();

        if (len == 1) {
            return true;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                zero_idx.push_back(i);
                cout << i << " ";
            }
        }
        cout << endl;

        if (zero_idx.size() == 0) {
            return true;
        }

        if (zero_idx.size() == len) {
            return false;
        }

        int idx = 0;

        while (idx < len) {
            if (idx >= zero_idx[0]) {
                return false;
            }

            if (zero_idx[0] == len - 1) {
                if (nums[idx] < (zero_idx[0] - idx)) {
                    cout << nums[idx] << " failed\n";
                    idx++;
                }
                else {
                    return true;
                }
            }

            if (zero_idx[0] != len - 1 && nums[idx] <= (zero_idx[0] - idx)) {
                cout << nums[idx] << " failed\n";
                idx++;
            }

            if (nums[idx] > (zero_idx[0] - idx)) {
                cout << zero_idx[0] << " popped\n";
                zero_idx.pop_front();
                if (zero_idx.size() == 0) {
                    return true;
                }
            }
        }

        return true;
    }
};
