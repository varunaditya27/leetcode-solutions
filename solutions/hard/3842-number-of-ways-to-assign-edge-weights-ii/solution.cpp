const int MOD = 1e9 + 7;
const int LOG = 17;

class Solution {
public:
    vector<int> depth;
    vector<array<int, LOG>> up;
    int n;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    void bfs(int root, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(root);
        depth[root] = 0;
        up[root][0] = root;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nxt : graph[node]) {
                if (depth[nxt] == -1) {
                    depth[nxt] = depth[node] + 1;
                    up[nxt][0] = node;
                    q.push(nxt);
                }
            }
        }
    }

    void buildLifting() {
        for (int k = 1; k < LOG; k++) {
            for (int v = 1; v <= n; v++) {
                up[v][k] = up[up[v][k-1]][k-1];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if ((diff >> k) & 1) {
                u = up[u][k];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;

        vector<vector<int>> graph(n + 1);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        depth.assign(n + 1, -1);
        up.assign(n + 1, {});

        bfs(1, graph);
        buildLifting();

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int l = lca(u, v);
            int d = depth[u] + depth[v] - 2 * depth[l];

            if (d == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)power(2, d - 1));
            }
        }

        return ans;
    }
};
