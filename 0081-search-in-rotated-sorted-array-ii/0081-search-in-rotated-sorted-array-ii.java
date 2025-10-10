class Solution {
    public boolean search(int[] nums, int target) {
        return search2(nums,target);
    }

    private static boolean search2(int[] arr,int target){
        int low = 0;
        int high = arr.length-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return true;
            }

            if(arr[mid]==arr[low]&&arr[mid]==arr[high]){
                low++;
                high--;
                continue;
            }

            if(arr[mid]>=arr[low]){
                //search for left side
                if(arr[low]<=target&&arr[mid]>=target){
                    high=mid-1;
                }else{ 
                    low=mid+1;
                } 
                
            }else if(arr[mid]<=arr[high]){
                if(arr[mid]<=target&&arr[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
}