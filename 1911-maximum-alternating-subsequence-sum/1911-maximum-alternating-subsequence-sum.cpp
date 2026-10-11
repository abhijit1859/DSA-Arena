class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int>& nums,int i,int sign){
        if(i>=nums.size()) return 0;
        int signIndex=(sign==1)?0:1;
        if(dp[i][signIndex]!=-1){
            return dp[i][signIndex];
        }
        long long take=sign*nums[i]+solve(nums,i+1,-sign);
        long long skip=solve(nums,i+1,sign);
        return dp[i][signIndex]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp.assign(nums.size(),vector<long long>(2,-1));
        return solve(nums,0,1);
    }


};