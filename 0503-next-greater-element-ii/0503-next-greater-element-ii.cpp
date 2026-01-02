class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=(n*2)-1;i>=0;i--){
            int el=nums[i%n];
            while(!s.empty()&&s.top()<=el){
                s.pop();
            }
            if(i<n){
                ans[i]=s.empty()?-1:s.top();
            }
           
            s.push(el);
        }


        return ans;
    }
};