class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        return find(nums,threshold);
    }

    private static int result(int[] nums,int mid){
        int result=0;
        for(int num:nums){
            result += (num+mid-1)/mid; 
        }
        return result;
    }

    private static int find(int[] nums,int threshold){
        int left = 1;  
        int right = 0; 

        for(int num : nums){
            if(num > right){
                right = num;
            }
        }
        int ans=-1;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(result(nums,mid)<=threshold){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
}