//shif n means sub 2^n times
//long ret=0
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long ret=0;
        long div1=labs(dividend),div2=labs(divisor);
        while(div1>=div2)
        {
            long temp=div2,m=1;
            while(temp<<1<=div1)
            {
                temp<<=1;
                m<<=1;
            }
            div1-=temp;
            ret+=m;
            
        }
        return ret*sign;
    }
};