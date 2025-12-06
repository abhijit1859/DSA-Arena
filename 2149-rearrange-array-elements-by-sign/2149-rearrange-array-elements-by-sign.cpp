class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int first=0;
        int second=1;
        for(auto num:nums){
            if(num>0){
                ans[first]=num;
                first+=2;
            }else{
                ans[second]=num;
                second+=2;
            }
        }
        return ans;
    }
};