class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows=grid.size();
        int cols=grid[0].size();
        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    fresh++;
                }else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        if (fresh==0) return 0;

        int minutes=0;
        vector<pair<int,int>> dir={
            {-1,0},{1,0},{0,-1},{0,1}
        };
        while(!q.empty()){
            int size=q.size();
            int rottenThisMinute=false;
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto [dr,dc]:dir){
                    int nr=r+dr;
                    int nc=c+dc;

                    while(nr>=0&&nr<rows&&nc>=0&&nc<cols&&grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        rottenThisMinute=true;
                        fresh--;
                    }
                }
            }

            if(rottenThisMinute) minutes++;
        }

        return (fresh==0) ? minutes:-1;
    }
};