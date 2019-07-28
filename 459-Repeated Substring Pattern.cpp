class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        vector<int>next(len+1,0);
        next[0]=-1;
        int i=0,j=-1;
        while(i<len)
        {
            if(j==-1||s[i]==s[j])
            {
                next[++i]=++j;
            }
            else
            {
                j=next[j];
            }
        }
        return next[len]&&next[len]%(len-next[len])==0;
    }
};
/*先求KMP算法中next数组,若重复k位,则next[len]非0且next[len]整除k，next[len]=len-k(根据next数组求法可得）*/
//next数组要多求一位