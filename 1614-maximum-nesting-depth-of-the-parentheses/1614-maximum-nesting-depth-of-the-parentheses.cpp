class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int depth=0;
        int maxDepth=0;
        for(char c:s){
            if(c=='('){
                depth++;
                maxDepth=max(maxDepth,depth);
                st.push(c);
            }else if(c==')'){
                depth--;
            }
        }
        return maxDepth;
    }
};