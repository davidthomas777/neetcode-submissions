class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row_l = 0, col_l = 0;           // inclusive
        int row_r = m - 1, col_r = n - 1;   // inclusive

        // keep going while l comes before or at r in reading order
        while (row_l < row_r || (row_l == row_r && col_l <= col_r)) {
            // cells from l to r, then walk half of that from l, carrying rows
            int dist = (row_r - row_l) * n + (col_r - col_l);
            int step = col_l + dist / 2;
            int mid_row = row_l + step / n;
            int mid_col = step % n;

            int curr = matrix[mid_row][mid_col];
            if (curr == target) return true;

            if (curr < target) {
                // l = mid + 1, carry into next row if needed
                if (mid_col + 1 == n) { row_l = mid_row + 1; col_l = 0; }
                else                  { row_l = mid_row;     col_l = mid_col + 1; }
            } else {
                // r = mid - 1, borrow from previous row if needed
                if (mid_col == 0) { row_r = mid_row - 1; col_r = n - 1; }
                else              { row_r = mid_row;     col_r = mid_col - 1; }
            }
        }
        return false;
    }
};
