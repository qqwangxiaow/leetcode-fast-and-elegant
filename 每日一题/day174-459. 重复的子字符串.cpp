//kmp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i=0,j=-1;
        int len=s.size();
        vector<int>next(len+1,0);
        next[0]=-1;
        while(i<len)
        {
            if(j==-1||s[i]==s[j])
            {
                next[++i]=++j;
            }
            else
                j=next[j];
        }
        return next[len]&&next[len]%(len-next[len])==0;
    }
};


//两个字符串拼接 然后寻找
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
