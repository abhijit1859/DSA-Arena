class Solution {
    public int maxProfit(int[] stock) {
        
       int maxProfit=0;
       int minStock = stock[0];
       
       for(int i=1;i<stock.length;i++){
           int profit=0;
           if(minStock>stock[i]){
               minStock=stock[i];
           }
           if(stock[i]>minStock){
               profit=stock[i]-minStock;
           }
           if(profit>maxProfit){
               maxProfit=profit;
           }
        
            
       }
       return maxProfit;
    }
}