class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0||grid[n-1][n-1]!=0) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1,-1, 1,-1, 0, 1};
        grid[0][0]=1; //visited
        int dist=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                if(r==n-1&&c==n-1) return dist;
                for(int i=0;i<8;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0){
                        grid[nr][nc]=1;//mark visited and push it into queue;
                        q.push({nr,nc});
                    }
                }

            }
            dist++;

        }

        return -1;
        
    }
};