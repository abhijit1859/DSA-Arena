class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int num:nums){
            high+=num;
        }

        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSplit(nums,mid,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }

    bool canSplit(vector<int>& nums,int max,int k){
        int count=1;
        int sum=0;
        for(int num:nums){
            if(sum+num>max){
                count++;
                sum=num;
            }else{
                sum+=num;
            }
        }

        return count<=k;
    }
};