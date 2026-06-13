class Solution {
public:
    void dfsHelper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int m, int n) {
        if (row >= m || col >= n || grid[row][col] == '0') return;
        visited[row][col] = true;
        
        if (grid[row][col] == '1') {
            if (row > 0 && !visited[row - 1][col]) dfsHelper(grid, visited, row - 1, col, m, n);
            if (row < m - 1 && !visited[row + 1][col]) dfsHelper(grid, visited, row + 1, col, m, n);
            if (col > 0 && !visited[row][col - 1]) dfsHelper(grid, visited, row, col - 1, m, n);
            if (col < n - 1 && !visited[row][col + 1]) dfsHelper(grid, visited, row, col + 1, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int res = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfsHelper(grid, visited, i, j, rows, cols);
                }
            }
        }

        return res;
    }
};
