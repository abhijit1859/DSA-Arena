class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int find=sum-k;
            if(map.find(find)!=map.end()){
                ans++;
                map[find]--;
            }
            map[sum]++;
        }

        return ans;
    }
};