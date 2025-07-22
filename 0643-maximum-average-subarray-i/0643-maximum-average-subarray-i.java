class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;

        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxAvg = sum / (double) k;  
       
        for (int i = k; i < nums.length; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxAvg = Math.max(maxAvg, sum / (double) k);
        }

        return maxAvg;
    }
}
