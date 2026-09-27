class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int rob=nums[i]+solve(nums,i+2,dp);
        int skip=solve(nums,i+1,dp);
        return dp[i]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
         
        vector<int> excLast(nums.begin(),nums.end()-1);
        vector<int> excFirst(nums.begin()+1,nums.end());

        vector<int> dp1(excLast.size(), -1);
        vector<int> dp2(excFirst.size(), -1);
        int ans1= solve(excLast,0,dp1);
        int ans2= solve(excFirst,0,dp2);
        return max(ans1,ans2);
    }
};