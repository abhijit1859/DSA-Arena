class Solution {
    public int numberOfSteps(int num) {
        int count =0;
        return helper(num,count);
    }
    private int helper(int n,int c){
        if(n==0){
            return c;
        }

        if(n%2==0){
            return helper(n/2,c+1);
        }else{
            return helper(n-1,c+1);
        }
    }
}