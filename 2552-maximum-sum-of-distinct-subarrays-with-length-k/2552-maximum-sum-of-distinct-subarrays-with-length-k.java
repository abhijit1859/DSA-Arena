class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
       HashMap<Integer,Integer> map = new HashMap<>();
       int left=0;
       long maxSum=0;
       long sum=0;
       for(int right=0;right<nums.length;right++){
        int curr=nums[right];
        map.put(curr,map.getOrDefault(curr,0)+1);
        sum+=curr;
        
        if(right-left+1>k){
            sum-=nums[left];
            map.put(nums[left],map.get(nums[left])-1);
            if(map.get(nums[left])==0){
                map.remove(nums[left]);
            }
            left++;
        }
        if(right-left+1==k&&map.size()==k){
            maxSum=Math.max(maxSum,sum);
        }
       }

       return maxSum;
       
      
    }
}