class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        genSub(nums,temp,0);
        return result;
    }

    void genSub(vector<int>& nums,vector<int>& temp,int index){
        if(index>=nums.size()){
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        genSub(nums,temp,index+1);
        temp.pop_back();
        genSub(nums,temp,index+1);
    }


};