class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> matrix(n, vector<long long>(n, LLONG_MAX));

        int len = edges.size();

        for (int i = 0; i < len; i++) {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; i++) matrix[i][i] = 0;

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        } */

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != LLONG_MAX && matrix[k][j] != LLONG_MAX) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        int min_cities = INT_MAX;
        int city;

        for (int i = 0; i < n; i++) {
            int city_count = 0;
            int cost = 0;
            cout << "i = " << i;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) {
                    city_count++;
                }
            }
            cout << " | cost = " << cost << endl;

            if (city_count <= min_cities) {
                city = i;
                min_cities = city_count;
                cout << i << " -> " << cost << endl;
            }
        }

        return city;
    }
};
