class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] memo=new int[amount+1];
        Arrays.fill(memo,-1);

        int result = helper(coins,amount,memo);
        return result==Integer.MAX_VALUE?-1:result;
    }

    private static int helper(int[] coins,int amount,int[] memo){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return Integer.MAX_VALUE;
        }

        if(memo[amount]!=-1){
            return memo[amount];
        }
        int minCoins=Integer.MAX_VALUE;

        for(int i=0;i<coins.length;i++){
            int res = helper(coins,amount-coins[i],memo);

            if(res!=Integer.MAX_VALUE){
                minCoins=Math.min(minCoins,1+res);
            }

        
        }
        memo[amount]=minCoins;

        return minCoins;
    }
}