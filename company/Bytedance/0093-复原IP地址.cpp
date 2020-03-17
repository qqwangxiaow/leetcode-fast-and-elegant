//valid ip should worry if(s[start]=='0'&&end!=start)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ret;
        string temp="";
        helper(ret,s,temp,0,0);
        return ret;
    }
    void helper(vector<string>&ret,string s,string &temp,int start,int len)
    {
        if(start==s.size()&&len==4)
        {
            ret.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(len<4&&i-start<3&&isvalidIP(s,start,i))
            {
                temp.append(s.substr(start,i-start+1));
                len++;
                if(len<4)
                    temp.push_back('.');
                helper(ret,s,temp,i+1,len);
                if(len<4)
                    temp.pop_back();
                len--;
                for(int j=0;j<i-start+1;j++)
                    temp.pop_back();
            }
            
        }
    }
    bool isvalidIP(string s,int start,int end)
    {
        string temp=s.substr(start,end-start+1);
        int ip=stoi(temp);
        if(s[start]=='0'&&end!=start)
            return false;
        else if(ip>=0&&ip<=255)
            return true;
        return false;
    }
};

//brute force 
//pay attention to 0000
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ret;
        string ans;
        for(int a=1;a<=3;a++)
        {
            for(int b=1;b<=3;b++)
            {
                for(int c=1;c<=3;c++)
                {
                    for(int d=1;d<=3;d++)
                    {
                        
                        if(a+b+c+d==s.size())
                        {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));
                            if(A<=255 && B<=255 && C<=255 && D<=255)
                            {
                                
                                if((ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                                    ret.push_back(ans);

                            } 

                        }
                        
                    }
                }
            }
        }
        return ret;

    }
};