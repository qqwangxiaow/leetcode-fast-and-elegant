//这个解法很好，先除以(n-1)!，就能确定第一位是什么
//k = 14(从0开始计数) index = k / (n-1)! = 2, 说明第15个数的第一位是3 
//同理再除以(n-2)!....
//最后把这些数字整合
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num="123456789";
        vector<int>f(n,1);
        for(int i=1;i<n;i++) f[i]=f[i-1]*i;
        --k;
        for(int i=n;i>=1;i--)
        {
            int j=k/f[i-1];
            k%=f[i-1];
            res.push_back(num[j]);
            num.erase(j,1);
        }
        return res;
    }
};

//这个直接调用库 next_permutation(iterator)
//代表下一个排列
class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)
        {
            s+=to_string(i+1);
        }
        while(--k)
        {
            next_permutation(s.begin(),s.end());
        }
        return s;
        
    }
};


