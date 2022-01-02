//1.f[i] + g[i] == i + 1
//2.f[i] = g[i/2] * 2
//3.f[i] = (i/2 + 1 - f[i/2]) * 2
//4.f[1] = 1
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};