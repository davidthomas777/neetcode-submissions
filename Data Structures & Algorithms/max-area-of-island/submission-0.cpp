class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;
        set<pair<int, int>> seen;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                // if a 1 and not seen before
                if (grid[i][j] == 1 && seen.count({i, j}) == 0) {
                    seen.insert({i, j});
                    int curr_area = 0;
                    check_neighbors(i, j, curr_area, grid, directions, seen);
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }

    void check_neighbors(int r, int c, int &curr_area, vector<vector<int>> &grid, vector<pair<int, int>> &directions, set<pair<int, int>> &seen) {
        curr_area += 1;
        for (pair<int, int> p : directions) {
            int new_r = r + p.first;
            int new_c = c + p.second;
            // FIX 5: Add bounds checking and seen check
            if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size() &&
                grid[new_r][new_c] == 1 && seen.count({new_r, new_c}) == 0) {
                seen.insert({new_r, new_c});
                check_neighbors(new_r, new_c, curr_area, grid, directions, seen);
            }
        }
    }
};