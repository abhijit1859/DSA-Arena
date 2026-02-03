class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        soln(nums,0,temp,0,target);
        return result;
    }

    void soln(vector<int>& nums,int index,vector<int>& temp,int sum,int target){
        if(sum==target){
            result.push_back(temp);
            return;
        }
        if(sum>target||index>=nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]) continue;
            sum+=nums[i];
            temp.push_back(nums[i]);
            soln(nums,i+1,temp,sum,target);
            temp.pop_back();
            sum-=nums[i];
        }
    }
};