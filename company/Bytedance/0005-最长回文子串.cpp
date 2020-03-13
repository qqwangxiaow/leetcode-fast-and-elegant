//extend
//keep l index and maxlen is better
class Solution {
public:
    string longestPalindrome(string s) {
        string ret="";
        if(s.size()==0)
            return ret;
        for(int i=0;i<s.size();i++)
        {
            extend(s,i,i,ret);
            extend(s,i,i+1,ret);
        }
        return ret;
    }
    void extend(string s,int i,int j,string &ret)
    {
        while(i>=0&&j<s.size())
        {
            if(s[i]==s[j])
            {
                if(j-i>=ret.size())
                {
                    ret=s.substr(i,j-i+1);
                }
                i--;
                j++;
            }
            else
                return;
        }
    }

};