//考虑多种情况
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(x==1)
            return 1;
        if(x==-1)
        {
            if(n%2)
                return -1;
            else 
                return 1;
        }
        if(n==INT_MIN)
            return 0;
        if(n<0)
        {
            x=1/x;
            n=-n;
        }
        double ret=1.0;
        while(n)
        {
            if(n&1)
            {
                ret*=x;
            }
            x*=x;
            n=n>>1;
        }
        return ret;
        
        
    }
};