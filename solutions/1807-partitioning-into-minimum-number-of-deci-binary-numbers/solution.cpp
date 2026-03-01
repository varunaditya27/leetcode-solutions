class Solution {
public:
    int minPartitions(string n) {
        int max_num = n[0] - '0';
        int len = n.size();

        for (int i = 0; i < len; i++) {
            max_num = max(max_num, n[i] - '0');
        }

        return max_num;
    }
};
