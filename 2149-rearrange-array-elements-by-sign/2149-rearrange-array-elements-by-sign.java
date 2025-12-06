class Solution {
    public int[] rearrangeArray(int[] nums) {
        int size=nums.length/2;
        int[] pos=new int[size];
        int index=0;
        int index2=0;
        int[] neg=new int[size];
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=0){
                pos[index]=nums[i];
                index++;
            }else{
                neg[index2]=nums[i];
                index2++;
            }
        }
        index=0;
        index2=0;

        for(int i=0;i<nums.length;i++){
            if(i%2==0){
                nums[i]=pos[index];
                index++;
            }else{
                nums[i]=neg[index2];
                index2++;
            }
        }
        System.out.println(Arrays.toString(pos));
        System.out.println(Arrays.toString(neg));
        return nums;
    }
}