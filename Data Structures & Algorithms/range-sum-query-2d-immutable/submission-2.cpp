class NumMatrix {
private:
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        sumMat = vector<vector<int>>(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int r = 0; r < ROWS; r++) {
            // row prefix sum
            int prefix = 0;
            for (int c = 0; c < COLS; c++) {
                prefix += matrix[r][c];
                // value above current
                int above = sumMat[r][c + 1];
                sumMat[r + 1][c + 1] = prefix + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        // bottom right
        int bottomRight = sumMat[row2][col2];
        // above row
        int above = sumMat[row1 - 1][col2];
        // left column
        int left = sumMat[row2][col1 - 1];
        // add back top left value
        int topLeft = sumMat[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};