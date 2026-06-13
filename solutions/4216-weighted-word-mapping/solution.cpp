class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int len = words.size();
        int weight;
        string res;

        for (int i = 0; i < len; i++) {
            int n = words[i].size();
            weight = 0;

            for (int j = 0; j < n; j++) {
                weight += weights[words[i][j] - 'a'];
            }

            res.push_back('z' - (weight % 26));
        }

        return res;
    }
};
