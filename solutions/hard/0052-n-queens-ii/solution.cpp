class Solution {
public:
    void solve(int n, vector<string>& board, int r, unordered_set<int>& cols, unordered_set<int>& left_diag, unordered_set<int>& right_diag, int& count) {
        if (r == n) {
            count++;
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

                solve(n, board, r + 1, cols, left_diag, right_diag, count);

                board[r][c] = '.';
                cols.erase(c);
                left_diag.erase(left);
                right_diag.erase(right);
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board;
        int res = 0;

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

        solve(n, board, 0, cols, left_diag, right_diag, res);

        return res;
    }
};
