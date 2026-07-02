class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(weights,days,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }

    bool canShip(vector<int>& weights,int days,int capacity){
        int total=0;
        int d=1;
        for(int weight:weights){
            if(total+weight<=capacity){
                total+=weight;
            }else{
                total=0;
                total+=weight;
                d++;
            }
        }

        return d<=days;
    }
};