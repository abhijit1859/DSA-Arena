class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

         priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        dist[0][0]=1;
        pq.push({1,{0,0}});

        while(!pq.empty()){
            auto [d,cell]=pq.top();
            pq.pop();
            int x=cell.first;
            int y=cell.second;


           
            for(auto &[dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;

                if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]==0){
                    if(d+1<dist[nx][ny]){
                        dist[nx][ny]=d+1;
                        pq.push({d+1,{nx,ny}});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==INT_MAX) return -1;

        return dist[n-1][n-1];



    }
};