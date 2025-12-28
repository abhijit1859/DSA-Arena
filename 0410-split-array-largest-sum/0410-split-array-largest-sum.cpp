class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int num:nums){
            high+=num;
        }

        int ans=-1;

        while(low<=high){
            int mid=(high-low)/2+low;
            if(isPossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool isPossible(vector<int>& arr,int max,int k){
        int part=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+sum>max){
                sum=arr[i];
                part++;
                if(part>k){
                    return false;
                }
            }else{
                sum+=arr[i];
            }
        }
        return true;
    }
};
