class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size()){
            return -1;
        }
        int low=1;
        int high=0;
        for(int day:bloomDay){
            high=max(high,day);
        }

        while(low<=high){
            int mid=(high-low)/2+low;
            if(bloom(bloomDay,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
          
        }

        return low;

    }

    bool bloom(vector<int>& bloomDay,int m,int k,int day){
        int c=0;
        int bq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                c++;
            }else{
                c=0;
            }
            if(c==k){
                bq++;
                c=0;
                if(bq==m){
                    return true;
                }
            }

        }
        return false;
    }
};