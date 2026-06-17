class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto &it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(numCourses==count){
            return true;
        }

        return false;

    }
};