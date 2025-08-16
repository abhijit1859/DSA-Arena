class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
    private int atMost(int[] arr,int k){
        Map<Integer,Integer> count = new HashMap<>();
        int left=0;
        int sub=0;

        for(int right=0;right<arr.length;right++){
            count.put(arr[right],count.getOrDefault(arr[right],0)+1);
            while(count.size()>k){
                count.put(arr[left],count.get(arr[left])-1);
                if (count.get(arr[left]) == 0) {
                    count.remove(arr[left]);
                }
                left++;
            }
            sub+=(right-left)+1;
        }
        return sub;
    }
}