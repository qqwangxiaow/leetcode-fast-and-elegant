//elegent
class Solution {
public:
    int binaryGap(int N) {
        int ret=0;
        for(int d=-32;N;N/=2,d++)
        {
            if(N%2==1)
            {
                ret=max(ret,d);
                d=0;
            }
        }
        return ret;
    }
};