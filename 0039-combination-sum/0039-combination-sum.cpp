class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        soln(candidates,target,temp,0,0);
        return result;
    }

    void soln(vector<int> nums,int target,vector<int> temp,int sum,int index){
        if(sum>target){
            return;
        }
        if(sum==target){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<nums.size();i++){
            sum+=nums[i];
            temp.push_back(nums[i]);
            soln(nums,target,temp,sum,i);
            temp.pop_back();
            sum-=nums[i];
        }
    }
};