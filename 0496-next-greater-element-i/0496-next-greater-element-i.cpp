class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i=nums2.size()-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.empty()&&st.top()<curr){
                st.pop();
            }
            mp[curr]=st.empty()?-1:st.top(); 
            st.push(curr);

        }

        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            int el=nums1[i];
            result.push_back(mp[el]);
        }

        return result;
    }
};