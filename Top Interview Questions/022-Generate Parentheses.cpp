//n represent num of '(' can be use,m - ')'
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        string temp;
        helper(ret,temp,n,0);
        return ret;
    }
    void helper(vector<string>&ret,string &temp,int n,int m)
    {
        if(m==0&&n==0)
        {
            ret.push_back(temp);
            return;
        }
        if(n>0)
        {
            temp.push_back('(');
            helper(ret,temp,n-1,m+1);
            temp.pop_back();
        }
        if(m>0)
        {
            temp.push_back(')');
            helper(ret,temp,n,m-1);
            temp.pop_back();
        }
        
    }
};