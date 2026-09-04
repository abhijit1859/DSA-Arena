class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxNo=INT_MIN;
        int minNo=INT_MAX;
        int ans=-1;
        vector<int> suffixMin(nums.size());
        suffixMin[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            maxNo=max(x,maxNo);
            minNo=suffixMin[i];
            int diff=maxNo-minNo;
            if(diff<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};