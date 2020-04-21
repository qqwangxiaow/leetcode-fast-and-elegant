//next[i]表示下一个循环哪个作为开头匹配
//counts[i]表示匹配了多少轮次
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int>next(s2.size(),0);
        vector<int>counts(s2.size(),0);
        for(int i=0;i<s2.size();i++)
        {
            int start=i;
            int cnt=0;
            for(int j=0;j<s1.size();j++)
            {
                if(s1[j]==s2[start])
                {
                     start++;
                    if(start==s2.size())
                    {
                        start=0;
                        cnt+=1;
                    }
                }      
            }
            next[i]=start;
            counts[i]=cnt;
        }
        int ret;
        int count=0,start=0;
        for(int i=0;i<n1;i++)
        {
            count+=counts[start];
            start=next[start];
        }
        ret=count/n2;
        return ret;
    }
};