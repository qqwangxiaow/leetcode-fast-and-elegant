//math break to 3*3*...*4
class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int count3=0;
        while(n>4)
        {
            count3++;
            n-=3;
        }
        int ret=n;
        while(count3--)
        {
            ret*=3;
        }
        return ret;
    }
};