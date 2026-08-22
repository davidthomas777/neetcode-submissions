class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (auto row : board) {
            set<int> row_nums;
            for (auto chr : row) {
                if (chr == '.') {
                    continue;
                }
                int num = chr - '0';
                if (row_nums.count(num) == 1) {
                    return false;
                }
                else {
                    row_nums.insert(num);
                }
            }
        }
        // column check
        for (int col = 0; col < 9; col++) {
            set<int> col_nums;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int num = board[row][col];
                if (col_nums.count(num) == 1) {
                    return false;
                }
                else {
                    col_nums.insert(num);
                }
            }
        }
        // 3x3 boxes check
        for (int box = 0; box < 9; box++) {
            set<char> box_nums;
            int start_row = (box / 3) * 3;
            int start_col = (box % 3) * 3;
            for (int i = start_row; i < start_row + 3; i++) {
                for (int j = start_col; j < start_col + 3; j++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (box_nums.count(board[i][j]) == 1) {
                        return false;
                    }
                    else {
                        box_nums.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
