/*异或求不同的位，再count */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y,ret=0;
        while(z)
        {
            ret+=(z)&0x01;
            z=z>>1;
            
        }
        return ret;
        
        
    }
};