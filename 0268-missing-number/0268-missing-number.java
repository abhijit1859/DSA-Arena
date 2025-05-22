class Solution {
    public int missingNumber(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        int count=0;
        while(count<length){
            if(nums[count]!=count){
                break;
            }
            count++;
        }
        return count;
    }
}