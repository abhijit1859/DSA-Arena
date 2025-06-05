class Solution {
    public int numRescueBoats(int[] arr, int target) {
        int b=0;
        Arrays.sort(arr);
        int left = 0;
        int right = arr.length-1;
        while(left<=right){
            int sum = arr[left]+arr[right];
            if(sum<=target){
                left++;
                right--;
            }else{
                right--;
            }
            b++;
            
        }
        return b;
    }
}