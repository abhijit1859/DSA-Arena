class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> prev;
        for(int x:nums){
            map<int,int> curr;
            curr[x]++;
            for(auto &[g,cnt]:prev){
                int newGcd=gcd(g,x);
                curr[newGcd]+=cnt;
            }
            ans+=curr[k];
            prev=curr;
        }
        return ans;
    }
};