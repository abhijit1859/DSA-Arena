class Solution {
public:
    vector<int> dijikstra(int src, int n,
                          vector<vector<pair<int, int>>>& graph) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();
            if (currDist > dist[node])
                continue;
            for (auto& [neigh, weight] : graph[node]) {
                if (currDist + weight < dist[neigh]) {
                    dist[neigh] = currDist + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans=-1;
        vector<vector<pair<int, int>>> graph(n);
        int minCount = INT_MAX;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        for (int city = 0; city < n; city++) {
            vector<int> dist = dijikstra(city, n, graph);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (j != city &&dist[j] <= distanceThreshold) {
                    count++;
                }
            }
            if(minCount>=count){
                minCount=count;
                ans=city;
            }
        }
        return ans;
    }
};