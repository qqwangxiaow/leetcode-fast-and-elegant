//1.pay attention n=INT_MIN,using long
//2.using & >> to quickly calculate
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        double ret=1;
        long t=n>0?n:-(long)n;
        while(t)
        {
            if(t&1)
                ret*=x;
            x*=x;
            t>>=1;
        }
        if(n<0)
            return 1/ret;
        else
            return ret;   
    }
};