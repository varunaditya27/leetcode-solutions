class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int len = s.size();
        int i = 0;
        int flag = 0;
        int row = 0, col = 0;
        vector<vector<char>> mat(numRows, vector<char>(2000));
        string res;

        while (i < len) {
            mat[row][col] = s[i];
            if (row == 0) {
                flag = 0;
            }
            else if (row == numRows - 1) {
                flag = 1;
            }
            if (flag == 0) {
                row++;
            }
            else if (flag == 1) {
                row--;
                col++;
            }
            i++;
        }
        for (int a = 0; a < numRows; a++) {
            for (int b = 0; b < col + 1; b++) {
                if (mat[a][b] != '\0')  {
                    res.push_back(mat[a][b]);
                }
            }
        }

        return res;
    }
};
