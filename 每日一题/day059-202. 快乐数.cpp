//two pointers
class Solution {
public:
    bool isHappy(int n) {
        int ret=0;
        int low=bitsum(n),fast=bitsum(low);
        while(low!=fast)
        {
            low=bitsum(low);
            fast=bitsum(bitsum(fast));
        }
        return low==1;
        
    }
    int bitsum(int n)
    {
        int ret=0;
        while(n)
        {
            int temp=n%10;
            ret+=temp*temp;
            n/=10;
        }
        return ret;
    }
};