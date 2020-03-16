class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
            return 0;
        int flag=x>=0?1:-1;
        int ret=0;
        x=flag>0?x:-x;
        while(x)
        {
            if(ret>INT_MAX/10||(ret==INT_MAX/10&&x>7))
            {
                return 0;
            }
            else
            {
                ret=ret*10+x%10;
            }
            x/=10;
        }
        return flag*ret;

    }
};