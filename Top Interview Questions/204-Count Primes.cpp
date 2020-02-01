//Sieve of Erantothoses
//建立一个vector 进行排除 如果是i的倍数那么就不行 
//优化方法是j从i*i开始 因为3*2 会被2*3先判断过
//注意n不包括 边界条件不用考虑、
class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return false;
        vector<int>isprime(n,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i*i<n;i++)
        {
            if(!isprime[i])
                continue;
            for(int j=i*i;j<n;j+=i)
            {
                isprime[j]=0;
            }
        }
        int ret=0;
        for(int i=0;i<n;i++)
        {
            if(isprime[i])
                ret++;
        }
        return ret;
        
    }
};