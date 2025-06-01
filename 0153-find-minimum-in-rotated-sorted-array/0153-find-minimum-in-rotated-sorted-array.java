class Solution {
    public int findMin(int[] nums) {
        //nt min = Integer.MIN_VALUE;

        return search(nums,0,nums.length-1);
        
    }
    private int search(int[] arr,int low,int high){
        if (low > high) return Integer.MAX_VALUE;
        int mid = (high+low)/2;

        int left = search(arr,low,mid-1);
        int right = search(arr,mid+1,high);

        return Math.min(arr[mid],Math.min(left,right));

    }
}