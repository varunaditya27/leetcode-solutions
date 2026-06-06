class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool found = false;

        int prev_bit = 0;
        int curr_bit;
        while (n > 0) {
            curr_bit = n & 1;

            if (curr_bit && prev_bit) {
                if (found) return false;

                found = true;
            }

            prev_bit = curr_bit;
            n = n >> 1;
        }
        
        return found;
    }
};
