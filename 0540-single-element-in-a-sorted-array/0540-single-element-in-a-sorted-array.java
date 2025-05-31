class Solution {
    public int singleNonDuplicate(int[] nums) {
        int ans = search(nums,0,nums.length-1);
        System.out.println(ans);
        return ans;
    }

    private static int search(int[] arr,int left,int right){
        if(left>right){
            return -1;
        }
        int mid =  (left+right)/2;
     
        //System.out.println(arr[mid]);
        if ((mid == 0 || arr[mid] != arr[mid - 1]) && 
            (mid == arr.length - 1 || arr[mid] != arr[mid + 1])) {
                
        return arr[mid];// This is the unique element
        }

        int leftans = search(arr,left,mid-1);
        if(leftans!=-1) return leftans;
      
        
        return search(arr,mid+1,right);
    }
}