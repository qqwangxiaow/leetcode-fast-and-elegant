//iterater
class Solution {
public:
    string countAndSay(int n) {
        string ret="1";
        while(--n)
        {
            ret=say(ret);
        }
        return ret;
    }
    string say(string pre)
    {
        string ret="";
        int count=0;
        for(int i=0;i<pre.size();i++)
        {
            count=1;
            while(i+1<pre.size()&&pre[i+1]==pre[i])
            {
                i++;
                count++;
            }
            ret+=to_string(count)+pre[i];
        }
        return ret;
    }
};