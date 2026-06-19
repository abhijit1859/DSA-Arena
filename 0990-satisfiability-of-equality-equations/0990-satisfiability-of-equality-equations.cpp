class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa!=pb){
            parent[pb]=pa;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(auto &eq:equations){
            if(eq[1]=='='){
                int x=eq[0]-'a';
                int y=eq[3]-'a';
                unite(x,y);
            }
        }

        for(auto &eq:equations){
            if(eq[1]=='!'){
                int x=eq[0]-'a';
                int y=eq[3]-'a';
                if(find(x)==find(y)){
                    return false;
                }
            }
        }

        return true;


    }
};