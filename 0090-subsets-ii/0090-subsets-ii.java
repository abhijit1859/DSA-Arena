 

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);  // important for handling duplicates
        return subset(nums);
    }

    private static List<List<Integer>> subset(int[] arr){
        List<List<Integer>> outer = new ArrayList<>();
        outer.add(new ArrayList<>()); // Start with empty subset

        for (int j = 0; j < arr.length; j++) {
            int n = outer.size();
            for (int i = 0; i < n; i++) {
                List<Integer> internal = new ArrayList<>(outer.get(i));
                internal.add(arr[j]);  // Always add arr[j]
                // Only add if it's not already in outer
                if (!outer.contains(internal)) {
                    outer.add(internal);
                }
            }
        }

        return outer;
    }
}
