//看有多少个5 因为2数量是溢出的
class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;
        for(long long i=5;i<=n;i*=5)
        {
            ret+=n/i;
        }
        return ret;
    }
};