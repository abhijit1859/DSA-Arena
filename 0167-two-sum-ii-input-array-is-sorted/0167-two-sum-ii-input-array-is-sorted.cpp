class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            int diff=numbers[right]+numbers[left];
            if(diff==target){
                return {left+1,right+1};
            }
            if(diff>target){
                right--;
            }else{
                left++;
            }
        }
        return {};
    }
};