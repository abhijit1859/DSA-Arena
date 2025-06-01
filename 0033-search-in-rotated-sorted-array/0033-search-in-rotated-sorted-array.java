class Solution {
    public int search(int[] nums, int target) {
        return search2(nums,target);
    }

    private static int search2(int[] arr,int target){
        int low = 0;
        int high = arr.length-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return mid;
            }
            //left part sorted ?
            if(arr[low]<=arr[mid]){
                //hai ya nhi ?
                if(arr[low]<=target&&arr[mid]>target){
                    //search left
                    high=mid-1;
                }else{
                    //search right;
                    low=mid+1;
                }
            }else{
                if(arr[mid]<target&&arr[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
}