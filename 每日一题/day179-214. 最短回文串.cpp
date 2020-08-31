//next数组求法注意 <(int)p.size()-1
//思想是求翻转过后的前后缀，因为这段是重复
class Solution {
public:
    int get_prefix(string p)
    {
        int i=0,j=-1;
        vector<int>next(p.size(),0);
        next[0]=-1;
        while(i<(int)p.size()-1)
        {
            if(j==-1||p[i]==p[j])
            {
                i++;
                j++;
                next[i]=j;
            }
            else
                j=next[j];
        }
        return next.back();
    }

    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string pattern=s+'#'+rev;
        int prefix=get_prefix(pattern)+1;
        return rev+s.substr(prefix);
    }
    
};