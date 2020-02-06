//(a&b)<<1  carry
//(a^b)=a+b with no carry
class Solution {
public:
    int getSum(int a, int b) {
        return b==0?a:getSum(a^b,(unsigned int)(a&b)<<1);  
    }
};