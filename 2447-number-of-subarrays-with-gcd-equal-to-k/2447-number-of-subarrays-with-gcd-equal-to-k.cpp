class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int g=0;
            for(int j=i;j<nums.size();j++){
                g=gcd(g,nums[j]);
                if(g==k) ans++;
                if(g<k) break;
            }
        }
        return ans;
    }
};