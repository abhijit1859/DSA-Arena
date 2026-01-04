class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            if(a>0||st.empty()){
                st.push(a);
            }else{
                while(!st.empty()&&st.top()>0&&st.top()<abs(a)){
                    st.pop();
                }
                if(!st.empty()&&st.top()==abs(a)){
                    st.pop();
                }else{
                    if(st.empty()||st.top()<0){
                        st.push(a);
                    }
                }
            }
        }

      
    

        vector<int> result;
        while(!st.empty()){
            int num=st.top();
            result.push_back(num);
            st.pop();
        }
        reverse(result.begin(),result.end());

        return result;
    }
};