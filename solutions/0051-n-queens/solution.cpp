#define SAFE 0
#define UNSAFE 1

class Solution {
public:
    void solve(int n, vector<vector<string>>& res, vector<string>& board, int r, unordered_set<int>& cols, unordered_set<int>& left_diag, unordered_set<int>& right_diag) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int left = c - r;
            int right = c + r;

            bool safe = !cols.contains(c) && !left_diag.contains(left) && !right_diag.contains(right);

            if (safe) {
                board[r][c] = 'Q';
                cols.insert(c);
                left_diag.insert(left);
                right_diag.insert(right);

                solve(n, res, board, r + 1, cols, left_diag, right_diag);

                board[r][c] = '.';
                cols.erase(c);
                left_diag.erase(left);
                right_diag.erase(right);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;

        string row;
        for (int i = 0; i < n; i++) {
            row.push_back('.');
        }

        for (int i = 0; i < n; i++) {
            board.push_back(row);
        }

        unordered_set<int> cols(n);
        unordered_set<int> left_diag(n);
        unordered_set<int> right_diag(n);

        solve(n, res, board, 0, cols, left_diag, right_diag);

        return res;
    }
};
