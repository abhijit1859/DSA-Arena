class Solution {
    public int[] twoSum(int[] nums, int target) {
       HashMap<Integer,Integer> map = new HashMap<>();
       for(int i=0;i<nums.length;i++){
        int complemented=target-nums[i];
        if(map.containsKey(complemented)){
            return new int[] {map.get(complemented),i};
        }

        map.put(nums[i],i);
       }
       return new int[] {};
    }
}