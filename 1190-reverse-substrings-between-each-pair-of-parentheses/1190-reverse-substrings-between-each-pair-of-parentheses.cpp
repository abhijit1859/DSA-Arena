class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr="";
        for(char c:s){
            if(c=='('){
                st.push(curr);
                curr="";
            }else if(c==')'){
                reverse(curr.begin(),curr.end());
                string previous=st.top();
                st.pop();
                curr=previous+curr;
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};