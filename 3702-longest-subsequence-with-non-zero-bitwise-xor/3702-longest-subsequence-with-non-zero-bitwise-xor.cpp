class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tx=0;
        int n=nums.size();
        for(int num:nums){
            tx^=num;
        }
        if(tx!=0){
            return n;
        }
        for(int x:nums){
            if(x!=0){
                return n-1;
            }
        }
        return 0;
    }
};