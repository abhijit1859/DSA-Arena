class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &adj,stack<int> &st){
        while(!adj[node].empty()){
            int next=adj[node].back();
            adj[node].pop_back();
            dfs(next,adj,st);
        }
        st.push(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for(auto edges:pairs){
            int u=edges[0];
            int v=edges[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int start=pairs[0][0];
        for(auto &[node,degree]:outdegree){
            if(outdegree[node]==indegree[node]+1){
                start=node;
                break;
            }
        }
        stack<int> st;
        dfs(start,adj,st);
        vector<int> path;
        while(!st.empty()){
            path.push_back(st.top());
            st.pop();
        }
        vector<vector<int>> ans;

        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }

        return ans;
    }
};