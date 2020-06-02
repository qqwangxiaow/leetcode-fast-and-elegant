class Solution {
public:
    int sumNums(int n) {
        int ret=n;
        ret&&(ret+=sumNums(n-1));
        return ret;
    }
};