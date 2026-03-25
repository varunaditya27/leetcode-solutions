class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<long long> row_prefix_sums;
        for (int row = 0; row < rows; row++) {
            long long row_sum = 0;
            for (int col = 0; col < cols; col++) {
                row_sum += grid[row][col];
            }
            if (row == 0) {
                row_prefix_sums.push_back(row_sum);
            }
            else {
                row_prefix_sums.push_back(row_sum + row_prefix_sums[row - 1]);
            }
        }

        if (rows != 1) {
            for (int i = 0; i < rows - 1; i++) {
                if (row_prefix_sums[rows - 1] == 2 * row_prefix_sums[i]) {
                    return true;
                }
            }
        }

        vector<long long> col_prefix_sums;
        for (int col = 0; col < cols; col++) {
            long long col_sum = 0;
            for (int row = 0; row < rows; row++) {
                col_sum += grid[row][col];
            }
            if (col == 0) {
                col_prefix_sums.push_back(col_sum);
            }
            else {
                col_prefix_sums.push_back(col_sum + col_prefix_sums[col - 1]);
            }
        }

        if (cols != 1) {
            for (int i = 0; i < cols - 1; i++) {
                if (col_prefix_sums[cols - 1] == 2 * col_prefix_sums[i]) {
                    return true;
                }
            }
        }

        return false;
    }
};
