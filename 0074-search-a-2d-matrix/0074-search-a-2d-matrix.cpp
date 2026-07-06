class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
             
            if(target>=matrix[mid][0]&&target<=matrix[mid][m-1]){
                int l=0;
                int h=m-1;
                while(l<=h){
                    int m=l+(h-l)/2;
                    if(matrix[mid][m]==target){
                        return true;
                    }else if(matrix[mid][m]>target){
                        h=m-1;
                    }else{
                        l=m+1;
                    }
                }
                return false;
            }else if(target<matrix[mid][0]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;

    }
};