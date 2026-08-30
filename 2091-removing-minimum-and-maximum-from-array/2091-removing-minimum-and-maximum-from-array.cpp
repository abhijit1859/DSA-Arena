class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minI=0;
        int maxI=0;
        //identifying min and max
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[minI]){
                minI=i;
            }else if(nums[i]>nums[maxI]){
                maxI=i;
            }
        }

        //abb gredily deletion ka nikalna hai
        int left=min(minI,maxI);
        int right=max(minI,maxI);

        //all possible ways
        int front=right+1;
        int back=n-left;
        int both=(left+1)+(n-right);

        return min(front,min(back,both));
    }
};