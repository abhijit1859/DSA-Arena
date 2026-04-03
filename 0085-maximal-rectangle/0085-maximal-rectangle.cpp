class Solution {
public:

    int largest(vector<int> &heights){
        int n=heights.size();
        vector<int> left(n),right(n);
        stack<int> st;
        //pse
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        //nse
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            maxArea=max(maxArea,width*heights[i]);
        }

        return maxArea;

        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int maxArea=0;
        for(auto row:matrix){
            for(int i=0;i<n;i++){
                if(row[i]=='1'){
                    heights[i]++;
                }else{
                    heights[i]=0;
                }
            }
            maxArea=max(maxArea,largest(heights));
        }
        return maxArea;
    }
};