class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //basically we have to find next greater so we can use monotonic stack concept
        int n=temp.size();
        vector<int> result(n,0);
        stack<int> st;
        int day=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&temp[st.top()]<temp[i]){
                int prev=st.top();
                st.pop();
                int diff=i-prev;
                result[prev]=diff;
               
            }
            st.push(i);
          
        }
        return result;
    }
};