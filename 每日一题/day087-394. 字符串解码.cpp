//next=decode(s,++start)
class Solution {
public:
    string decodeString(string s) {
        int start=0;
        return decode(s,start);
    }
    string decode(string s,int &start)
    {
        string ret="";
        int num=0;
        for(;start<s.size();start++)
        {
            auto ch=s[start];
            if(ch<='9'&&ch>='0')
            {
                num=num*10+ch-'0';
            }
            else if(ch=='[')
            {
                string next=decode(s,++start);
                for(;num>0;num--)
                {
                    ret+=next;
                }
            }
            else if(ch==']')
                return ret;
            else
                ret+=ch;
        }
        return ret;
        
    }
};