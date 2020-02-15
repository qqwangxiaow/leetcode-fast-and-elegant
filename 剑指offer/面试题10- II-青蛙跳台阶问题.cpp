//if 0 return 1
class Solution {
public:
    int numWays(int n) {
        if(n<=1)
            return 1;
        long pre1=1,pre2=1;
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