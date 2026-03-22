class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         
        int maxCons=0;
        int cons=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
            cons++;
            maxCons=max(maxCons,cons);
           }else{
            cons=0;
           }
            
        }

        return maxCons;
    }
};