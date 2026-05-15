class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> radius(n,-1);
        vector<long long> prefix(n+1,0);
        
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=k;i<n-k;i++){
            long long sum=prefix[i+k+1]-prefix[i-k];
            radius[i]=sum/(2*k+1);
        }
        return radius;
    }
};