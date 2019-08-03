/*mask 取unsigned,钢开始为11111111，
num          = 00000101
mask         = 11111000
~mask & ~num = 00000010 */
class Solution {
public:
    int findComplement(int num) {
        unsigned mask=~0;
        while(mask&num)
        {
            mask<<=1;
        }
        return ~mask&~num;
        
        
        
    }
};