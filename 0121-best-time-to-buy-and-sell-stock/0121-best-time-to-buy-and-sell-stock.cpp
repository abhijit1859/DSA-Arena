class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int currStock=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<=currStock){
                maxProfit=0;
                currStock=prices[i];
            }else{
                maxProfit=max(maxProfit,prices[i]-currStock);
            }
        }
        return maxProfit;
    }
};