class Solution {
public:
    bool dfs(int node,vector<int>& state,vector<vector<int>>& adj){
        state[node]=1;
        for(auto& neigh:adj[node]){
            if(state[neigh]==0){
                if(dfs(neigh,state,adj)){
                    return true;
                }
            }
            if(state[neigh]==1){
                return true;
            }
        }
        state[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(dfs(i,state,adj)){
                return false;
            }
        }
        return true;
    }
};