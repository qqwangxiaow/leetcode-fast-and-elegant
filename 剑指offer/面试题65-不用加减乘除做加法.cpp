//^就是进位和
//&和<<就是进位 然后再^ 直到没有进位
class Solution {
public:
    int add(int a, int b) {
        while(b)
        {
            int temp=a^b;
            b=(unsigned int)(a&b)<<1;
            a=temp;
        }
        return a;
    }
};