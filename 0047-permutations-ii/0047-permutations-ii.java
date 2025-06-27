class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        boolean[] used = new boolean[nums.length]; 
        List<Integer> list = new ArrayList<>();
       List<List<Integer>> result = new ArrayList<>();
        permute(nums,list,result,used);
        System.out.println(result);
        return result;
    }
    private static void permute(int[] arr,List<Integer> list,List<List<Integer>> result,boolean[] used){
        
        if(list.size()==arr.length){
            if(!result.contains(list)){
                result.add(new ArrayList<>(list));
                return;
            }
                       
        }
        
        for(int i=0;i<arr.length;i++){
            if(used[i]==true) continue;
            list.add(arr[i]);
            used[i]=true;
            permute(arr,list,result,used);
            list.remove(list.size()-1);
            used[i]=false;
        }
        
    
    }
}