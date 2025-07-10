class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];

        Arrays.fill(dp,-1);
        return selectHouse(nums,0,dp);
    }

    private static int selectHouse(int[] arr,int idx,int[] dp){
        if(idx>=arr.length) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int loot = arr[idx]+selectHouse(arr,idx+2,dp);
        int skip = selectHouse(arr,idx+1,dp);
        dp[idx] = Math.max(loot,skip);
        return dp[idx];
    }
}