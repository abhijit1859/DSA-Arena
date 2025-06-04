class Solution {
    public boolean isPowerOfTwo(int n) {
        return search(n);
    }

   private static boolean search(int n){
    if(n==1){
        return true;
    }

    if(n==0){
        return false;
    }

     
    if(n%2==0){
        return search(n/2);
    }else{
        return false;
    }
   }
}