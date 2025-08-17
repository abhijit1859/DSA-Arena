class Solution {
    public double findMaxAverage(int[] nums, int k) {
       int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        int maxSum=windowSum;
       for(int i=k;i<nums.length;i++){
        windowSum+=nums[i]-nums[i-k];
        maxSum=Math.max(windowSum,maxSum);
       }
       return (double) maxSum/k;
    }
}
//[1,12,-5,-6,50,3]
//[1,13,8,2,52,55]