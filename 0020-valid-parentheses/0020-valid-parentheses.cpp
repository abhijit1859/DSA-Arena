class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c:s){
            
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(check(st.top(),c)){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }

    bool check(char top,char curr){
        if(top=='('&&curr==')') return true;
        if(top=='['&&curr==']') return true;
        if(top=='{'&&curr=='}') return true;
        return false;
    }
};