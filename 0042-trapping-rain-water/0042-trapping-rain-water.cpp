class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[i]>height[st.top()]){
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                int right=height[i];
                int left=height[st.top()];

                int bounded=min(right,left)-height[top];
                int width=i-st.top()-1;
                water+=bounded*width;
            }
            st.push(i);
        }
        return water;
    }
};