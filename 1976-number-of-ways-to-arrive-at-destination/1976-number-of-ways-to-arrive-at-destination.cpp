class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        //[u,v,time]
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> count(n,0);
        vector<vector<pair<int,long long>>> adj(n);
        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            int t=road[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        //dist,node
        pq.push({0,0});
        dist[0]=0;
        count[0]=1;

        while(!pq.empty()){
            auto [currDist,node]=pq.top();
            pq.pop();

            if(currDist>dist[node]) continue;
            for(auto &it:adj[node]){
                int neigh=it.first;
                int wt=it.second;
                if(currDist+wt<dist[neigh]){
                    pq.push({currDist+wt,neigh});
                    dist[neigh]=currDist+wt;
                    count[neigh]=count[node];
                }else if(currDist+wt==dist[neigh]){
                    count[neigh]=(count[neigh]+count[node])%mod;
                }
            }
        }

        return count[n-1];


    }
};