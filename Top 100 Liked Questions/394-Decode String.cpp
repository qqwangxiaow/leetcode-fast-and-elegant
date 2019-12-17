//recrusive   i means place 
class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
    string decode(string &s,int &i)
    {
        string ret;
        while(i<s.size()&&s[i]!=']')
        {
            if(!isdigit(s[i]))
            {
                ret+=s[i++];
            }
            else
            {
                int n=0;
                while(i<s.size()&&isdigit(s[i]))
                {
                    n=n*10+s[i++]-'0';
                }
                i++;
                string t=decode(s,i);
                i++;
                while(n--)
                {
                    ret+=t;
                }
            }
        }
        return ret;
    }

};