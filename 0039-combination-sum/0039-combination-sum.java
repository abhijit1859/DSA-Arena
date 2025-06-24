class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> outer = new ArrayList<>();
        List<Integer> comb = new ArrayList<>();
        sum(candidates,0,target,outer,comb);
        return outer;
        
    }
    private static void sum(int[] arr,int index,int target,List<List<Integer>> outer,List<Integer> comb){
        if(target==0){
            if(!outer.contains(comb)){
                outer.add(new ArrayList<>(comb));
            }
             
            return;
        }
        if(index==arr.length||target<0){
            return;
        }
        
        comb.add(arr[index]);
        sum(arr,index+1,target-arr[index],outer,comb);
        sum(arr,index,target-arr[index],outer,comb);
        comb.remove(comb.size()-1);
        sum(arr,index+1,target,outer,comb);
    }
}