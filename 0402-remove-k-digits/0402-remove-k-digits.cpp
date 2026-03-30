class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(char c:num){
            while(!st.empty()&&st.top()>c&&k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        int idx=0;
        while(idx<n&&ans[idx]=='0'){
            idx++;
        }
        ans=ans.substr(idx);
        return ans.empty()?"0":ans;
    }
};