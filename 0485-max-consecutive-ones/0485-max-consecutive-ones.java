class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
         int count=0;
        int countMax=0;
        for(int i=0;i<nums.length;i++){
            if((nums[i]^1)==0){
                count++;
            }else{
                if(count>countMax){
                    countMax=count;
                }
                count=0;
            }
            if(count>countMax){
                    countMax=count;
            }

        }
        
        return countMax;
       
    }
}