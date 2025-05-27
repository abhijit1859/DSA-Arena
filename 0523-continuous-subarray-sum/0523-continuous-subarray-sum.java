class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
         
        int sum=0;
        
        HashMap <Integer,Integer> map = new HashMap<>();
        map.put(0, -1);
        for(int i=0;i<nums.length;i++){
             sum+=nums[i];
            
            sum=sum%k;
            
            if(map.containsKey(sum)){
                int prevIndex=map.get(sum);
                if((i-prevIndex)>=2){
                    return true;
                }
            }else{
                map.put(sum,i);
            }
           

            
        }
        return false;
    }
}