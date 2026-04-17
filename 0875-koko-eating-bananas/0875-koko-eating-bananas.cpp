class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int pile:piles){
            high=max(high,pile);
        }

        while(low<=high){
            int mid=(high-low)/2+low;
            if(canEat(piles,h,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;

    }

    bool canEat(vector<int> &piles,int h,int speed){
        int time=0;
        for(int pile:piles){
            time+=(pile+speed-1)/speed;
            if(time>h) return false;
        }
        return true;

    }
};