class Solution {
    public int maxDistance(int[] position, int m) {
        return findMax(position,m);
    }
    private static boolean canPlace(int[] position,int m,int dist){
        int count=1;
        int lastPos = position[0];
        for(int i=0;i<position.length;i++){
            if(position[i]-lastPos>=dist){
                count++;
                lastPos=position[i];
            }
            if(count==m){
                return true;
            }
        }
        return false;
    }


    private static int findMax(int[] position,int m){
        Arrays.sort(position);
        int low = 1;
        int ans=0;
        int high = position[position.length-1]-position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canPlace(position,m,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
}