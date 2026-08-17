class Solution {
public:
    vector<vector<int>> result;
    int sum=0;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        gen(k,n,temp,1);
        return result;
    }

    void gen(int k,int n,vector<int> temp,int curr){
        if(temp.size()==k){
            if(sum==n){
                result.push_back(temp);
            }
            return;
        }

        if(sum>n) return;

        for(int i=curr;i<=9;i++){
            temp.push_back(i);
            sum+=i;
            gen(k,n,temp,i+1);
            sum-=i;
            temp.pop_back();
        }
    }
};