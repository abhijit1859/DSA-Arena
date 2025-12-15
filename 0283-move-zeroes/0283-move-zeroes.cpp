class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        while(nums[left]!=0&&left<nums.size()){
            left++;
        }
        for(int i=left+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[left],nums[i]);
                left++;
            }
        }
        
    }
};