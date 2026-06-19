class Solution {
public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;

        if(rank[px]<rank[py]){
            parent[px]=py;
        }else if(rank[px]>rank[py]){
            parent[py]=px;
        }else{
            parent[py]=px;
            rank[px]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int extraCables=0;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)){
                extraCables++;
            }else{
                Union(u,v);
            }
        }

        int components=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                components++;
            }
        }

        int needed=components-1;
        if(extraCables>=needed){
            return needed;
        }
        return -1;

    }
};