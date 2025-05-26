class Solution {
    public int subarraySum(int[] arr, int k) {
        
        
        int currSum=0;
        
        int count=0;
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<arr.length;i++){
            currSum+=arr[i];
            if(currSum==k){
                count++;
            }
            if(map.containsKey(currSum-k)){
                count=count+map.get(currSum-k);
            }
            map.put(currSum, map.getOrDefault(currSum, 0) + 1);

            
            
        }
        return count;
    }
}