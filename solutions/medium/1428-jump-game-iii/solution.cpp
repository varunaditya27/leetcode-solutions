class Solution {
    bool dfs(const vector<int>& arr, vector<bool>& visited, int i) {
        if (i < 0 || i >= arr.size() || visited[i]) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }
        visited[i] = true;

        int jump = arr[i];
        bool right = dfs(arr, visited, i + jump);
        if (right) {
            return true;
        }

        bool left = dfs(arr, visited, i - jump);
        return left;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, visited, start);
    }
};
