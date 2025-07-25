class Solution {
    public int longestOnes(int[] nums, int k) {
        return flip(nums,k);
    }

    private static int  flip(int[] arr,int k){
        int left=0;
        int right=0;
        int count=0;
        int maxLen=0;
        while(right<arr.length){
            if(arr[right]==0){
                count++;
            }
            if(count>k){
                if(arr[left]==0){
                    count--;
                }
                left++;
            }

            maxLen=Math.max(maxLen,right-left+1);

            right++;
        }
        return maxLen;
    }
}