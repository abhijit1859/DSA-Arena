class Solution {
    public int[] findPeakGrid(int[][] mat) {
        return findPeak(mat);
    }

    private static int[] findPeak(int[][] mat){
        int m=mat.length;
        int n=mat[0].length;
        int left=0;
        int right=mat[0].length-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            int max=0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[max][mid]){
                    max=i;
                }
            }
            int leftN = (mid-1>0)?mat[max][mid-1]:-1;
            int rightN = (mid+1<n)?mat[max][mid+1]:-1;
            if(mat[max][mid]>leftN&&mat[max][mid]>rightN){
                return new int[]{max,mid};
            }else if(mat[max][mid]<leftN){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return new int[]{-1,-1};
    }
}