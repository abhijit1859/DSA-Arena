class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[prev]){
                swap(nums[i],nums[prev+1]);
                prev++;

            }

        }

        return prev+1;
    }
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
};