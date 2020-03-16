//看成一堆树 以1为根 2为根。。。
//gap就是计算两个数之间差了多少字典序 差的多的画就直接跳 比如从1 直接到2
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        while(k>1)
        {
            int gap=findgap(cur,cur+1,n);
            if(gap<k)
            {
                k-=gap;
                cur++;
            }
            else
            {
                cur=cur*=10;
                k-=1;
            }
        }
        return cur;
    }
    int findgap(long a,long b,int n)
    {
        long gap=0;
        while(a<=n)
        {
            gap+=min(long(n+1),b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
};