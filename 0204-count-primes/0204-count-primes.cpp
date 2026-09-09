class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int> prime(n,1);
        int count=1;

        for(int i=3;i*i<n;i+=2){
            if(prime[i]){
                for(int j=i*i;j<n;j+=2*i){
                    prime[j]=0;
                  
                }
            }
        }

        for(int i=3;i<n;i+=2){
            if(prime[i]) count++;
        }
     

        return count;
    }
};