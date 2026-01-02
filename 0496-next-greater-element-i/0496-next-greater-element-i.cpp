class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            int el=nums2[i];
            while(!s.empty()&&s.top()<=el){
                s.pop();
            }
            mp[el]=s.empty()?-1:s.top();
            s.push(el);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};