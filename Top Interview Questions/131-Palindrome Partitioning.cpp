//回溯 判断是不是palindrome 把s分成一段一段 最后组装起来
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ret;
        vector<string>tmp;
        helper(ret,tmp,s,0);
        return ret;
    }
    void helper(vector<vector<string>>&ret,vector<string>&tmp,string &s,int start)
    {
        if(start==s.size())
        {
            ret.push_back(tmp);
        }
        for(int i=start;i<s.size();i++)
        {
            if(ispalindrome(s,start,i))
            {
                tmp.push_back(s.substr(start,i-start+1));
                helper(ret,tmp,s,i+1);
                tmp.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};