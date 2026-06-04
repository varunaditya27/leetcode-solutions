class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string, int> map;
        int idx = 0;

        int len = equations.size();
        for (int i = 0; i < len; i++) {
            if (!map.contains(equations[i][0])) {
                map[equations[i][0]] = idx;
                idx++;
            }
            if (!map.contains(equations[i][1])) {
                map[equations[i][1]] = idx;
                idx++;
            }
        }

        int n = idx;
        vector<vector<double>> matrix(n, vector<double>(n, -1.0));

        for (int i = 0; i < len; i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            matrix[map[a]][map[b]] = values[i];
            matrix[map[b]][map[a]] = 1.0/values[i];
        }

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 1.0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == -1 && matrix[i][k] != -1 && matrix[k][j] != -1) {
                        matrix[i][j] = matrix[i][k] * matrix[k][j];
                    }
                }
            }
        }

        int N = queries.size();
        for (int i = 0; i < N; i++) {
            string A = queries[i][0];
            string B = queries[i][1];

            if (!map.contains(A) || !map.contains(B)) {
                res.push_back(-1.0);
            }
            else {
                res.push_back(matrix[map[A]][map[B]]);
            }
        }

        return res;
    }
};
