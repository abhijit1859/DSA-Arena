class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> squares(n);
        for(int i=0;i<n;i++){
            squares[i]=1LL*nums[i]*nums[i];
        }
        nth_element(squares.begin() , squares.begin() + n/2 , squares.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans-=squares[i];
            }else{
                ans+=squares[i];
            }
        }
        return ans;
    }
};