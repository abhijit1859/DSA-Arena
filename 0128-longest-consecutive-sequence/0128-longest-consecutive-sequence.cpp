class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(int x:st){
            if(st.contains(x-1)) continue;

            int num=x;
            int cur=1;
            while(st.contains(num+1)){
                cur++;
                num++;
            }
            ans=max(ans,cur);

        }
        return ans;
    }
};