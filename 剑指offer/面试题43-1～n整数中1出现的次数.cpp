//recrusive
class Solution {
public:
    int countDigitOne(int n) {
        return dfs(n);
    }
    int dfs(int n)
    {
        if(n<=0)
            return 0;
        string str=to_string(n);
        int high=str[0]-'0';
        int power=(int)pow(10,str.size()-1);
        int last=n-high*power;
        if(high==1)
        {
            return dfs(power-1)+last+1+dfs(last);
        }
        else
        {
            return power+high*dfs(power-1)+dfs(last);
        }
    }
};
//
class Solution {
public:
    int countDigitOne(int n) {
        int count=0;
        long long i;
        for(i=1;i<=n;i*=10)
        {
            int a=n/i,b=n%i;
            count=count+(a+8)/10*i+(a%10==1)*(b+1);
        }
        return count;
        
    }
};