class Solution {
    public int removeElement(int[] arr, int val) {
         int left=0;
         int right=arr.length-1;
         while(left<=right){
            if(arr[left]==val){
                arr[left]=arr[right];
                right--;
            }else{
                left++;
            }
         }
         return left;
    }
 
}