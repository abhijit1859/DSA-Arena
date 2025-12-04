class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
         
        while(nums[left]!=0){
            left++;
        }
        int right=left+1;
         

        while(right<nums.size()){
            if(nums[left]==0&&nums[right]==nums[left]){
                right++;
            }else{
                swap(left,right,nums);
                left++;
                right++;
                
            }
        }
        
    }

    void swap(int left,int right,vector<int>& v){
        int temp=v[left];
        v[left]=v[right];
        v[right]=temp;
    }
};