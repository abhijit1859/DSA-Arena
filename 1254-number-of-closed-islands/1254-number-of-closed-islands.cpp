class Solution {
public:
    int m, n;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool isClosed = true;
        for (auto& d : dirs) {
            int dx = i + d[0];
            int dy = j + d[1];
            bool result = dfs(grid, dx, dy);
            if (!result) {
                isClosed = false;
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};