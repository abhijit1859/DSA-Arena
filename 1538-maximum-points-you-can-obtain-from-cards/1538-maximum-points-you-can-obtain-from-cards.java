class Solution {
    public int maxScore(int[] cardPoints, int k) {
            int n = cardPoints.length;
        
        int[] ps1 = new int[n];
        int[] ps2 = new int[n];
        
        ps1[0] = cardPoints[0];
        ps2[n-1] = cardPoints[n-1];
        
        for (int i = 1; i < n; i++) {
            ps1[i] = ps1[i-1] + cardPoints[i];
        }
        
        for (int i = n-2; i >= 0; i--) {
            ps2[i] = ps2[i+1] + cardPoints[i];
        }
        
       int max=0;
       for(int i=0;i<=k;i++){
        int leftSum=(i>0)?ps1[i-1]:0;
        int rightSum=(k-i>0)?ps2[n-(k-i)]:0;
        max=Math.max(max,leftSum+rightSum);
       }

         

        return max;
    }

}