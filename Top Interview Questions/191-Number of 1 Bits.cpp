//n&(n-1)也能很快得出1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            n&=(n-1);
            count++;
        }
        return count;
    }
};
//基本的
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++,n=n>>1)
        {
            count+=(n&1);
        }
        return count;
    }
};