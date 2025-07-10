class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.length+1];
        Arrays.fill(dp,-1);
        int c1=minCost(cost,0,dp);
        int c2=minCost(cost,1,dp);
        return Math.min(c1,c2);
    }

    private static int minCost(int[] arr,int idx,int[] dp){
        if(idx>=arr.length){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int oneStep=minCost(arr,idx+1,dp);
        int twoStep=minCost(arr,idx+2,dp);
        dp[idx] = arr[idx] + Math.min(oneStep, twoStep);
        return dp[idx];
    }
}