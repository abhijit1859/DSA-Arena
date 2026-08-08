class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> id;
        int cnt=0;
        for(auto& eq:equations){
            if(!id.count(eq[0])){
                id[eq[0]]=cnt++;
            }
            if(!id.count(eq[1])){
                id[eq[1]]=cnt++;
            }
        }

        int n=cnt;
        vector<vector<double>> dist(n,vector<double>(n,-1.0));
        for(int i=0;i<n;i++){
            dist[i][i]=1.0;
        }
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double w=values[i];
            dist[id[u]][id[v]]=w;
            dist[id[v]][id[u]]=1.0/w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(dist[i][k]!=-1&&dist[k][j]!=-1){
                        dist[i][j]=dist[i][k]*dist[k][j];
                    }
                }
            }
        }

        vector<double> ans;
        for(auto& query:queries){
            string u=query[0];
            string v=query[1];
            if(!id.count(u)||!id.count(v)){
                ans.push_back(-1.0);
            }else{
                ans.push_back(dist[id[u]][id[v]]);
            }
        }

        return ans;
    }
};