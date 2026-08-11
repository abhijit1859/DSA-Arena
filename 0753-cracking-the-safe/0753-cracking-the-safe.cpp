class Solution {
public:
    string crackSafe(int n, int k) {
        string startNode=string(n-1,'0');
        unordered_set<string> visited;
        string result="";

        dfs(startNode,k,visited,result);
        result+=startNode;
        return result;
    }
    void dfs(const string& node,int k,unordered_set<string>& visited,string& result){
        for(int i=0;i<k;i++){
            string edge=node+to_string(i);
            if(!visited.count(edge)){
                visited.insert(edge);
                string nextNode=edge.substr(1);
                dfs(nextNode,k,visited,result);
                result+=to_string(i);
            }
        }
    }
};