class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int,int>> dir = {
            {-1,0}, {1,0}, {0,-1}, {0,1}
        };

        

        while(!pq.empty()){
            auto [currEffort,cell]=pq.top();
            pq.pop();

            int x=cell.first;
            int y=cell.second;
            if(x==n-1&&y==m-1) return currEffort;
            if(currEffort>dist[x][y]) continue;

            for(auto [dx,dy]:dir){
                int nx=x+dx;
                int ny=y+dy;

                if(nx>=0&&ny>=0&&nx<n&&ny<m){
                    int diff=abs(heights[x][y]-heights[nx][ny]);
                    int newEffort=max(currEffort,diff);

                    if(newEffort<dist[nx][ny]){
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }

        return 0;

    }
};