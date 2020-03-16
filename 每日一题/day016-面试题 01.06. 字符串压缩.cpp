class Solution {
public:
    string compressString(string S) {
        string ret=compress(S);
        if(ret.size()<S.size())
            return ret;
        else    
            return S;
    }
    string compress(string S)
    {
        if(S.empty())
            return "";
        if(S.size()==1)
            return S+'1';
        int count=1;
        string ret="";
        int j=1;
        for(int i=0;i<S.size();i=j)
        {
            count=1;
            for(j=i+1;j<S.size();j++)
            {
                if(S[j]==S[j-1])
                    count++;
                else
                {
                    break;    
                }
            }
            ret+=S[i]+to_string(count);   
        }
        return ret;
        
    }
};