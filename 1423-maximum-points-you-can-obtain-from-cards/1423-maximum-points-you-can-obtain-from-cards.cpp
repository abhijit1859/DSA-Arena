class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
            
        }
        maxSum=sum;
        int right=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[right];
            right--;
            maxSum=max(maxSum,sum);

        }
        return maxSum;
    }
};