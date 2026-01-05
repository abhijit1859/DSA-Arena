class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n-1;i++){
            int max=nums[i];
            int min=nums[i];
            
            for(int j=i+1;j<n;j++){
                if(nums[j]>max) max=nums[j];
                if(nums[j]<min) min=nums[j];
                res+=max-min;
            }
        }
        return res;
    }
};