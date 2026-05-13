class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int sum=0;
        int j=0;
        int len=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[j];
                j++;
            }
            len+=(i-j+1);
        }
        return len;
    }
};