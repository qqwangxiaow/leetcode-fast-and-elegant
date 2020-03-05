//f(n,m)=(f(n-1,m)+m)%n;
//表示有n个人 隔m报数时剩下人的坐标
//f(1,m)=0 一个人,那么这个人剩下，坐标为0
//每杀一个人 胜利者的坐标会-m 反过来就是+m 会越界 所以mod i
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ret=0;
        for(int i=2;i<=n;i++)
        {
            ret=(ret+m)%i;
        }
        return ret;
    }
};