class Solution {
public:
    int lastRemaining(int n, int m) {
        //f(n,m)=(f(n-1,m)+m)%n;
        int ret=0;
        for(int i=2;i<=n;i++)
        {
            ret=(ret+m)%i;
        }
        return ret;
    }
};