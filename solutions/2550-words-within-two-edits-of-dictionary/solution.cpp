class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for (string query: queries) {
            int len = query.size();

            for (string target: dictionary) {
                int flag = 0;
                for (int i = 0; i < len; i++) {
                    if (query[i] != target[i]) {
                        flag++;
                    }
                    if (flag > 2) break;
                }

                if (flag <= 2) {
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};
