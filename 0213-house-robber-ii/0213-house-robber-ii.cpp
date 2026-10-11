class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(nums,i+2,dp);
        int skip=solve(nums,i+1,dp);
        return dp[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        vector<int> execLast(nums.begin(),nums.end()-1);
        vector<int> execFirst(nums.begin()+1,nums.end());

        vector<int> dp1(execLast.size(),-1);
        vector<int> dp2(execFirst.size(),-1);

        return max(solve(execLast,0,dp1),solve(execFirst,0,dp2));
    }
};