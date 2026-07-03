class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            int missing=arr[i]-(i+1);
            if(missing>=k){
                return i+k;
            }

        }

        return n+k;
    }
};