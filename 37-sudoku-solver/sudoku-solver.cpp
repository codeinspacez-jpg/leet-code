class Solution {
public:
    bool solveSudoku(vector<vector<char>>& b, int r = 0, int c = 0) {
        if (r == 9) return true;
        if (c == 9) return solveSudoku(b, r + 1, 0);
        if (b[r][c] != '.') return solveSudoku(b, r, c + 1);
        
        for (char d = '1'; d <= '9'; ++d) {
            if (isValid(b, r, c, d)) {
                b[r][c] = d;
                if (solveSudoku(b, r, c + 1)) return true;
                b[r][c] = '.';
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& b, int r, int c, char d) {
        for (int i = 0; i < 9; ++i)
            if (b[r][i] == d || b[i][c] == d || b[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == d)
                return false;
        return true;
    }
};