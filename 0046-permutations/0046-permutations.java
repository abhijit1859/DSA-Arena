class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        subset(nums,new ArrayList<>(),result);
        return result;
    }

    private static void subset(int[] arr,List<Integer> path,
    List<List<Integer>> result){
        if(path.size()==arr.length){
            System.out.println(path);
            result.add(new ArrayList<>(path));
            return;
        }

        for(int i=0;i<arr.length;i++){
            if(path.contains(arr[i])) continue;

            path.add(arr[i]);
            subset(arr,path,result);
            path.remove(path.size()-1);

        }
    }
}