class Solution {
    public int shipWithinDays(int[] weights, int days) {
        return getMinDays(weights,days);
    }


    private int getMinDays(int[] weights,int days){
        int left=getMax(weights);
        int right=total(weights);
        while(left<right){
            int mid = (left+right)/2;
            if(canShip(weights,mid,days)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }

    private boolean canShip(int[] weights,int capacity,int days){
        int count=1;
        int currentLoad=0;
        for(int i=0;i<weights.length;i++){
            if(currentLoad+weights[i]>capacity){
                count++;
                currentLoad=0;
            }
            currentLoad+=weights[i];
        }
        return count<=days;
    }

    private int total(int[] weights){
        int total=0;
        for(int i=0;i<weights.length;i++){
            total+=weights[i];
        }
        return total;
    }

    private int getMax(int[] weights){
        int max=weights[0];
        for(int i=1;i<weights.length;i++){
            if(weights[i]>max){
                max=weights[i];
            }
        }

        return max;
    }
}