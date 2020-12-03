//Sieve of Erantothoses
//筛选掉倍数
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