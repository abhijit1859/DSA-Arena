class Solution {
    public List<Integer> findDuplicates(int[] arr) {
        Arrays.sort(arr);
        int j=0;
        int count=1;
        ArrayList<Integer> list = new ArrayList<>();

        for(int i=1;i<arr.length;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            if(arr[i]!=arr[i-1]&&count==2){
                list.add(arr[i-1]);
                count=1;
            }
            if(i==arr.length-1&&count==2){
                list.add(arr[i]);
            }
        }

        return list;
    }
}