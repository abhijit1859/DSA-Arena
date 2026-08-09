class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        mp[0]=1;
        int sum=0;
        for(int x:nums){
            sum+=x;
            int need=sum-k;
            if(mp.count(need)){
                ans+=mp[need];
            }
            mp[sum]++;
        }
        return ans;
    }
};