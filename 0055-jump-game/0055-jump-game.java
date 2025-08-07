class Solution {
    public boolean canJump(int[] nums) {
        Boolean[] memo = new Boolean[nums.length];
        return jump(nums,0,memo);
    }

    private static boolean jump(int[] nums,int i,Boolean[] memo){
        if(i>=nums.length-1){
            return true;
        }
        if(memo[i]!=null) return memo[i];
        int maxJump=nums[i];
        for(int step=1;step<=maxJump;step++){
            if(jump(nums,i+step,memo)){
                memo[i]=true;
                return true;
            }
            
        }
        memo[i]=false;

        return false;
    }
}