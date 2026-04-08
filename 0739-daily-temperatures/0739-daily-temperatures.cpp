class Solution {
public:
    class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int diff=i-st.top();
                result[st.top()]=diff;
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};;