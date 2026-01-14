class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
    
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto days:bloomDay){
            if(days<low){
                low=days;
            }
            if(days>high){
                high=days;
            }
        }
        int n=bloomDay.size();
        if((long long)m*k>n ){
            return -1;
        }
        
        int ans=high;
        while(low<=high){
            int mid=(high-low)/2+low;

            if(canBloom(mid,m,k,bloomDay)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }

        return ans;
        
    }

    bool canBloom(int days,int m,int k,vector<int> arr){
        int c=0;
        int bq=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=days){
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