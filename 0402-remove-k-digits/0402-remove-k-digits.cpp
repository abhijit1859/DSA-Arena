class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(char c : num){
            while(!st.empty()&&k>0&&st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        
        reverse(ans.begin(),ans.end());
        int idx=0;
        while(idx<ans.size()&&ans[idx]=='0'){
            idx++;
           
        }
        ans=ans.substr(idx);
        return ans.empty()?"0":ans;
    }
};