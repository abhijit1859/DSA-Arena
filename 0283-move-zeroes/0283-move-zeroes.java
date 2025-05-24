class Solution {
    public void moveZeroes(int[] arr) {
       
        int i;
        for(i=0;i<arr.length;i++){
            if(arr[i]==0){
                break;
            }
        }
        System.out.println(i);
        
        for(int j=i+1;j<arr.length;j++){
            if(arr[j]!=0){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                i++;
            }
        }
        
    }
}