//构造string 如果想要O（1）space 那么可以从后往前遍历字符串
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string ss,tt;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='#')
            {
                ss+=S[i];
            }
            else if(!ss.empty())
            {
                ss.pop_back();
            }
        }
        for(int i=0;i<T.size();i++)
        {
            if(T[i]!='#')
            {
                tt+=T[i];
            }
            else if(!tt.empty())
            {
                tt.pop_back();
            }
        }
        return tt==ss;
        
        
    }
};