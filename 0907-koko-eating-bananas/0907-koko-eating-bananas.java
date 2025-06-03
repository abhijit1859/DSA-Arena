class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        return minTime(piles,h);
    }

    private static int bananaEatingTime(int[] piles,int k){
        int hours = 0;
        for(int i =0;i<piles.length;i++){
            hours += (int) Math.ceil((double) piles[i] / k);

        }
        return hours;
    }

    private static int minTime(int[] piles,int h){
        int low = 1;
        int high = getMax(piles);
        
        while(low<high){
            int mid = low + (high - low) / 2;
            if(bananaEatingTime(piles,mid)<=h){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }

    private static int getMax(int[] piles){
        int max = piles[0];
        for(int i=1;i<piles.length;i++){
            if(piles[i]>max){
                max=piles[i];
            }
        }
        return max;
    }
}