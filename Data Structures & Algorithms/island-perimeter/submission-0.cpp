class Solution {
    int row;
    int col;
    int perimeter = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    set<pair<int, int>> seen;

public:
    bool in_bounds(int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col) return false;
        return true;
    }

    void propagate_island(vector<vector<int>>& grid, int i, int j) {
        perimeter += 4;
        seen.insert({i, j});
        for (pair<int, int> dir : directions) {
            int new_i = i + dir.first;
            int new_j = j + dir.second;
            if (in_bounds(new_i, new_j) && grid[new_i][new_j] == 1) {
                perimeter -= 1;
                if (seen.count({new_i, new_j}) == 0) {
                    propagate_island(grid, new_i, new_j);
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // perimter = total number of sides of island, each side is 1 added
        row = grid.size();
        col = grid[0].size();
        int i = 0;
        int j = 0;
        bool found = false;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        propagate_island(grid, i, j);
        return perimeter;
    }
};