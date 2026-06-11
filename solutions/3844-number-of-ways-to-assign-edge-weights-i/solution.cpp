const int MOD = 1e9 + 7;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> graph(n + 1);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int,int>> q;
        vector<int> visited(n + 1, 0);

        q.push({1, 0});
        visited[1] = 1;

        int res = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            res = max(res, depth);

            for (int next : graph[node]) {
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, depth + 1});
                }
            }
        }

        if (res == 0) return 0;

        return (int)power(2, res - 1);
    }
};
