class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        vector<int> v;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);

 
    }

    void reverse(vector<int>& v,int left,int right){
        while(left<=right){
            int temp=v[left];
            v[left]=v[right];
            v[right]=temp;
            left++;
            right--;
        }
    }

   
};