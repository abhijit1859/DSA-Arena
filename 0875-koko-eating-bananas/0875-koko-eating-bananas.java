class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        return minEating(piles,h);
        
    }

    private static boolean canEatAll(int[] piles,int h,int k){
        int hours = 0;
        for(int pile:piles){
            hours += (pile + k - 1) / k;

            if(hours>h) return false;
        }

        return hours<=h;
    }

    public static int minEating(int[] piles,int h){
        int low=0;
        int high=0;
        for(int pile:piles){
            high=Math.max(high,pile);
        }
        int ans=high;

        while(low<=high){
            int mid = (low+high)/2;
            if(canEatAll(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

}