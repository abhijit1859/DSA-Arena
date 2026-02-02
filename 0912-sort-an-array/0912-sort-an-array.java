class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums,0,nums.length-1);
        return nums;
    }

    private static void mergeSort(int[] arr,int left,int right){
        if(left<right){
            int mid = left+(right-left)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);

            merge(arr,left,mid,right);

        }
    }

    private static void merge(int[] arr,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;

        int[] l=new int[n1];
        int[] r=new int[n2];

        for(int i=0;i<n1;i++){
            l[i]=arr[i+left];
        }
        for(int j=0;j<n2;j++){
            r[j]=arr[mid+1+j];
        }

        int i=0,j=0;
        int k=left;
        while(i<n1&&j<n2){
            if(l[i]<=r[j]){
                arr[k]=l[i];
                i++;
            }else{
                arr[k]=r[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k]=l[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k]=r[j];
            j++;
            k++;
        }
    }
}