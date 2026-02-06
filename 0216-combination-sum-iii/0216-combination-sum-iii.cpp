class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        genSub(temp,1,0,k,n);
        return result;
    }

    void genSub(vector<int> &temp,int curr,int sum,int k,int n){

        if(temp.size()==k){
            if(sum==n){
                result.push_back(temp);
            }
            return;
        }

        if(sum>n) return;


        for(int i=curr;i<=9;i++){
           
            temp.push_back(i);
            genSub(temp,i+1,sum+i,k,n);
            temp.pop_back();
          
        }
    }


};