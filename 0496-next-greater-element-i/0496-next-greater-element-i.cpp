class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        for(int i=0;i<nums1.size();i++){
            int el=nums1[i];
            int index=-1;

            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==el){
                    index=j;
                    break;
                }
              
            }
            int nextGreater=-1;
            for(int j=index+1;j<nums2.size();j++){
                if(nums2[j]>el){
                    nextGreater=nums2[j];
                    break;
                            
                }
            }
            results.push_back(nextGreater);

        }
        return results;
    }
};