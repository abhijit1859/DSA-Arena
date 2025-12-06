class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int closet=nums[0]+nums[1]+nums[2];

        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
          
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(abs(sum-target)<abs(closet-target)){
                    closet=sum;
                }
                if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }
          
        }
          return closet;
    }
};