class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};
        int fresh=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        int minutes=0;

        while (!q.empty()) {

            int size = q.size();
            bool rottenThisMinute = false;
            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                            fresh--;
                            rottenThisMinute=true;
                        }
                    }
                }
            }
            if(rottenThisMinute) minutes++;
        }
        if(fresh>0) return -1;
        return minutes;
    }
};