class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums,int target,int i){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(nums[i]<=target){
            take=solve(nums,target-nums[i],i+1);
        }
        bool skip=solve(nums,target,i+1);
        return dp[i][target]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        dp.assign(nums.size(),vector<int>(target+1,-1));
        if(sum%2!=0) return false;
        return solve(nums,sum/2,0);

    }
};