class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col]=0;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+delRow[i];
                int nc=col+delCol[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==1) bfs(i,0,grid);
            if(grid[i][m-1]==1) bfs(i,m-1,grid);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) bfs(0,j,grid);
            if(grid[n-1][j]==1) bfs(n-1,j,grid);
        }

        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};