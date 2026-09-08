class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        if(divisor==1) return dividend;

        int sign=(dividend<0)^(divisor<0)?-1:1;

        int ans = 0;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            n = n - (d << cnt);
        }
        return sign>0?ans:-ans;
    }
};