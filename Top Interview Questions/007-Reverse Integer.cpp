//INT_MAX/10<ret||(INT_MAX-x%10)<ret*10  to judge overflow
class Solution {
public:
    int reverse(int x) {
        int sign=x>0?1:-1;
        if(x==INT_MIN)
            return 0;
        x=abs(x);
        int ret=0;
        while(x)
        {
            if(INT_MAX/10<ret||(INT_MAX-x%10)<ret*10)
            {
                return 0;
            }
            ret=ret*10+x%10;
            x/=10;
        }
        return sign*ret;   
    }
};