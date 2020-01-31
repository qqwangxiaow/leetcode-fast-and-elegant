//一位一位来 将n >> 1 与1 & 方便些
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0;i<32;i++,n=n>>1)
        {
            ret=ret<<1;
            ret=ret|(n&1);
        }
        return ret;
    }
};