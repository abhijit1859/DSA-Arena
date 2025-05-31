class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] sample = {-1,-1};
        int ans = search(sample,nums,0,nums.length-1,target);
        System.out.println(Arrays.toString(sample));
        return sample;
    }

    private static int search(int[] sample,int[] arr,int low ,int high,int x){
        
        if(low>high){
            return -1;
        }
        
        int mid = (low+high)/2;
        
       if(arr[mid]==x){
            if(sample[0]==-1|| mid < sample[0]) sample[0]=mid;
            
            if(sample[1]==-1|| mid > sample[1]) sample[1]=mid;
            
            search(sample,arr,low,mid-1,x);
            
            search(sample,arr,mid+1,high,x);
            System.out.println(Arrays.toString(sample));
           
        }else if(arr[mid]>x){
            search(sample,arr,low,mid-1,x);
        }else{
            search(sample,arr,mid+1,high,x);
        }
       return 0;
    }
}