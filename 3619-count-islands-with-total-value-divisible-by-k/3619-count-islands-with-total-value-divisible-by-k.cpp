class Solution {
public:
    int m, n;
    int dr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    long long solve(
        vector<vector<int>> & grid,int i,int j) {
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1 || grid[i][j] == 0)
            return 0;
        long long sum = grid[i][j];
        grid[i][j] = 0;
        for (auto& [dx, dy] : dr) {
            int ni = dx + i;
            int nj = dy + j;
            sum += solve(grid, ni, nj);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long sum = solve(grid,i,j);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};