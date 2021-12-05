//快速幂 利用a的10的b次方 等于 a的10次方的b次方
class Solution {
public:
    const int MOD = 1337;
    int pow(int x, int n) {
        int res = 1;
        while(n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = (long) ans * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }
};