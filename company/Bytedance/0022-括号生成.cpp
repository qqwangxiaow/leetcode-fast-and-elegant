//using m and n to control
//init m=0,n=n;
//(n>0) m+1,n-1
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        helper(ret,"",0,n);
        return ret;
    }
    void helper(vector<string>&ret,string temp,int m,int n)
    {
        if(m==0&&n==0)
        {
            ret.emplace_back(temp);
            return;
        }
        if(n>0) helper(ret,temp+'(',m+1,n-1);
        if(m>0) helper(ret,temp+')',m-1,n);    
    }
};