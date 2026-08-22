class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> indices;

        // row
        for (int i = 0; i < matrix.size(); i++) {
            // col
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    indices.push_back({i, j});
                }
            }
        }

        for (pair<int, int> p : indices) {
            // set all values in column index p.second to 0
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][p.second] = 0;
            }

            // set all values in row index p.first to 0
            for (int j = 0; j < matrix[p.first].size(); j++) {
                matrix[p.first][j] = 0;
            }
        }
    }
};
