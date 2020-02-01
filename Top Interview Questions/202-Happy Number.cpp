//two pointers
class Solution {
public:
    bool isHappy(int n) {
        int low=n,fast=n;
        do
        {
            low=bitsquaresum(low);
            fast=bitsquaresum(bitsquaresum(fast));
        }
        while(low!=fast);  
        return fast==1;
        
    }
    int bitsquaresum(int n)
    {
        int ret=0;
        while(n)
        {
            int d=n%10;
            ret+=d*d;
            n=n/10;
        }
        return ret;
    }
};