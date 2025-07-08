class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        return minTime(piles,h);
    }

    private int minTime(int[] piles,int h){
        int low=1;
        int high=Arrays.stream(piles).max().getAsInt();
        while(low<high){
            int mid = (high+low)/2;
            if(bananaEatingTime(piles,mid)<=h){
                high=mid;
            }else{
                low=mid+1;
            }
        }

        return low;
    }

    private int bananaEatingTime(int[] piles,int k){
        int hours=0;
        for(int i=0;i<piles.length;i++){
            double div = (double)piles[i]/k;
            hours+=Math.ceil(div);

        }
        return hours;
    }
 

    
}