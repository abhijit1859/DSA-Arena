class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        mp[0]=1;
        int sum=0;
        for(int x:nums){
            sum+=x;
            if(mp.contains(sum-k)){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};