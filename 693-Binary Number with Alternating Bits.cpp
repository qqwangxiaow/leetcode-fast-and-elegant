//检查是否都是1
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n=n^(n>>1);
        return !(n&(long)n+1);
    }
};