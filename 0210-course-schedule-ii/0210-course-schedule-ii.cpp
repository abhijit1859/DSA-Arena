class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);

        for(auto &it:prerequisites){
            int course=it[0];
            int prerequisite=it[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(result.size()!=numCourses){
            return {};
        }

        return result;
    }
};