//注意overflow, /2 处理  +1 -1 都有可能
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return integerReplacement(n / 2) + 1;
        } else {
            return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        }
    }
};