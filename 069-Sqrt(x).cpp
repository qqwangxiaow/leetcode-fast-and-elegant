//pay attention
//return r, l<=r and mid=x/mid for not overflow
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int l=1,r=x;
        while(l<=r)   
        {
            int mid=l+(r-l)/2;
            if(mid<=x/mid)
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
         r;
    }
};