//return pre2 not cur
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        long pre1=0,pre2=1;
        long cur=0;
        while(--n)
        {
            cur=pre1+pre2;
            pre1=pre2;
            pre2=cur%1000000007;
        }
        return pre2;
    }
};