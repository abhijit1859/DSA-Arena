class Solution {
    public boolean checkPrimeFrequency(int[] nums) {
        HashMap<Integer,Integer> freq = new HashMap<>();
        for(int num:nums){
            if(freq.containsKey(num)){
                freq.put(num, freq.get(num) + 1);
            }else{
                freq.put(num,1);
            }
        } 

        boolean foundPrime = false;
        for(int key:freq.keySet()){
            int value = freq.get(key);
            if(isPrime(value)){
                return true;
            }
        }
        return false;
    }

    static boolean isPrime(int n) {
    if (n <= 1) return false;  
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

    
    
}