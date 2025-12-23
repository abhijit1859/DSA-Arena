class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        return find(bloomDay,m,k);
    }
    private static int canMake(int[] bloomDay,int mid,int k){
        int bouqCount=0;
        int c=0;
        for(int i=0;i<bloomDay.length;i++){
            if(bloomDay[i]<=mid){
                c++;
            }else{
                c=0;
            }
            if(c==k){
                bouqCount++;
                c=0;
            }
        }

        return bouqCount;
    }

    private static int find(int[] bloomDay,int m,int k){
        int start=1;
        int end=-1;
        for(int day:bloomDay){
            if(day>=end){
                end=day;
            }
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(canMake(bloomDay,mid,k)>=m){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
}