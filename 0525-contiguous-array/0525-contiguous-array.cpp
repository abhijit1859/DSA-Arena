class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        int ans=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            sum+=x;
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};