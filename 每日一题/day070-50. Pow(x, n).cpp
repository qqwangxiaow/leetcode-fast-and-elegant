//quick pow
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(x==1)
            return 1;
        long long N=n;
        if(n<0)
        {
            x=1/x;
            N=-N;
        }
        return quickpow(x,N);
    }
    double quickpow(double x,int n)
    {
        if(n==0)
            return 1;
        double half=quickpow(x,n/2);
        if(n%2==0)
            return half*half;
        else
            return half*half*x;
    }
};