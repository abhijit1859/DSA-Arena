class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }

    bool bfs(int node,vector<vector<int>>& graph,vector<int> color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto neigh:graph[curr]){
                if(color[neigh]==-1){
                    color[neigh]=1-color[curr];
                    q.push(neigh);
                }else if(color[neigh]==color[curr]){
                    return false;
                }
            }
        }
        return true;
    }
};