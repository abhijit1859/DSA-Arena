class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid;
        grid.assign(m,vector<char>(n,'#'));
        if(m==1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j]='.';
                }
            }
        }
        for(int j=0;j<n;j++){
            grid[0][j]='.';
        }

        for(int i=0;i<m;i++){
            grid[i][n-1]='.';
        }

        vector<string> ans;
        for(int i=0;i<m;i++){
            ans.emplace_back(grid[i].begin(),grid[i].end());
        }
        return ans;
    }
};