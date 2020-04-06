//m=(l+r)/2+1
//l=m
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        long l=1,r=x/2;
        while(l<r)
        {
            int  m=l+(r-l)/2+1;
            if(m>x/m)
                r=m-1;
            else
                l=m;
        }
        return l;
    }
};