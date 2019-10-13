//考虑0的情况 0不可能被整除 !(a%10)
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ret;
        for(int i=left;i<=right;i++)
        {
            if(isdivide(i))
            {
                ret.push_back(i);
            }
        }
        return ret;
        
    }
    bool isdivide(int num)
    {
        if(num<=0)
            return false;
        int n=num;
        while(n)
        {
            int a=n%10;
            n=n/10;
            if(!(a%10)||num%a!=0)
                return false;
        }
        return true;
    }
};