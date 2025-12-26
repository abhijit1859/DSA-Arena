class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1];
        int ans=-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(canDivide(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
                
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool canDivide(vector<int>& nums,int threshold,int div){
        int ans=0;
        for(auto num:nums){
           ans+=ceil((double)(num)/(double)(div));
           if(ans>threshold){
            return false;
           }
        }
        return true;
    }
};