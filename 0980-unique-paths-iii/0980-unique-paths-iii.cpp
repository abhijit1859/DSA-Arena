class Solution {
public:
    int nonObstacles=0;
    int m,n;
    int results=0;
    vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x=0,y=0;
        m=grid.size();
        n=grid[0].size();
        
        
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                    x=i;
                    y=j;
                }
                if(grid[i][j]!=-1){
                    nonObstacles++;
                }
            }
        }

        backtrack(grid,x,y,count);
        return results;
    }

    void backtrack(vector<vector<int>>& grid,int i,int j,int count){
        if(i<0||i>=m||j>=n||j<0||grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(count==nonObstacles){
                results++;
            }
            return;
        }

        grid[i][j]=-1;
        for(vector<int> dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            backtrack(grid,i_,j_,count+1);
        }

        grid[i][j]=0;
    }
};