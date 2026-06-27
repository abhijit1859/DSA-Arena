class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<pair<int,int>> dir = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto &[dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;
                while(nx>=0&&ny>=0&&nx<n&&ny<m&&dist[nx][ny]==-1){
                    dist[nx][ny]=1+dist[x][y];
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};