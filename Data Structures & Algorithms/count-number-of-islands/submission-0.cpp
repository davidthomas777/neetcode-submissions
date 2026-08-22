class Solution {
public:
    set<pair<int, int>> index_set; // visited cells
    int num_islands = 0;

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && index_set.count({i, j}) == 0) {
                    // Found a new island
                    num_islands++;
                    process_grid(i, j, grid);
                }
            }
        }
        return num_islands;
    }

    void process_grid(int r, int c, vector<vector<char>>& grid) {
        if (!in_bounds(r, c, grid) || grid[r][c] != '1' || index_set.count({r, c})) {
            return; // out of bounds, water, or already visited
        }

        index_set.insert({r, c});

        // Explore all 4 directions
        process_grid(r - 1, c, grid); // up
        process_grid(r + 1, c, grid); // down
        process_grid(r, c - 1, grid); // left
        process_grid(r, c + 1, grid); // right
    }

    bool in_bounds(int r, int c, vector<vector<char>>& board) {
        return r >= 0 && r < board.size() && c >= 0 && c < board[r].size();
    }
};
