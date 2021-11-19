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

//贪心 其实 +1 是更好的 因为他能消除更多的1 
//除以2相当于右移

class Solution {
public:
    int integerReplacement(int _n) {
        int ret = 0;
        long n = _n;
        while(n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n != 3 && ((n >> 1 & 1) == 1)) {
                n++;
            } else {
                n--;
            }
            ret++;
        }
        return ret;
    }
};