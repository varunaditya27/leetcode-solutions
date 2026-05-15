class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        int s_len = s.size();
        int track;
        int idx;

        for (int i = 0; i < s_len; i++) {
            if (s[i] == goal[0]) {
                track = (i + 1) % s_len;
                idx = 1;
                while (track != i) {
                    if (s[track] != goal[idx]) {
                        break;
                    }
                    else {
                        idx++;
                        track = (track + 1) % s_len;
                    }
                }
                if (track == i) {
                    return true;
                }
            }
        }

        return false;
    }
};
