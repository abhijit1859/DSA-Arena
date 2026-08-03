class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto& edges : times) {
            int u = edges[0];
            int v = edges[1];
            int w = edges[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // dist,node
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();
            if(currDist>dist[node]) continue;

            for (auto& it : adj[node]) {
                int neigh = it.first;
                int weight = it.second;
                if (currDist + weight < dist[neigh]) {
                    dist[neigh] = currDist + weight;
                    pq.push({currDist + weight, neigh});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            } else {
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};