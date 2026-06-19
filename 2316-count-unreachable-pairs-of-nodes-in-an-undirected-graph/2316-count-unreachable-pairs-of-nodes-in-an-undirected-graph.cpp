class Solution {
public:
    vector<int> parent,rank,size;
    int find(int x){
        if(parent[x]==x) return parent[x];
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]){
            parent[px]=py;
            size[py]+=size[px];
        }else if(rank[px]>rank[py]){
            parent[py]=px;
            size[px]+=size[py];
        }else{
            parent[py]=px;
            size[px]+=size[py];
            rank[px]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto edge:edges){
            Union(edge[0],edge[1]);
        }
        long long ans=0;
        long long remaining=n;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                ans+=1LL*size[i]*(remaining-size[i]);
                remaining-=size[i];
            }
        }

        return ans;

    }
};