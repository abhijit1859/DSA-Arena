class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                if((x==0||y==0||x==n-1||y==m-1)&&!(x==entrance[0]&&y==entrance[1])){
                    return steps;
                }
                for (auto& [dr, dc] : dir) {
                    int nx = dr + x;
                    int ny = dc + y;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        maze[nx][ny] == '.') {
                        q.push({nx, ny});
                        maze[nx][ny] = '+';
                    }
                }
            }

            steps++;
        }
        return -1;
    }
};