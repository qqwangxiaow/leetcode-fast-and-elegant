class Solution {
public:
    int integerBreak(int n) {
        int ret=0,count=0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        while(n>4)
        {
            n-=3;
            count++;
        }
        ret=n;
        while(count--)
        {
            ret*=3;
        }
        return ret;
        
    }
};