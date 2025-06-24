class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = subset(nums);
        return list;
    }

    private static List<List<Integer>> subset(int[] arr){
        List<List<Integer>> outer = new ArrayList<>();
        outer.add(new ArrayList<>());
        for(int j=0;j<arr.length;j++){
            int n=outer.size();
            for(int i=0;i<n;i++){
                List<Integer> internal = new ArrayList<>(outer.get(i));
                internal.add(arr[j]);
                if(!outer.contains(internal)){
                     outer.add(internal);
                }
               
            }
        }

        return outer;
    }
}