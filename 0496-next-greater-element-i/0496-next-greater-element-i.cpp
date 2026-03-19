class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        unordered_map<int,int> mp;
        stack<int> st;
        for(int num:nums2){
            while(!st.empty()&&st.top()<num){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }

        for(int num:nums1){
            results.push_back(mp[num]);
        }

        return results;
    }
};