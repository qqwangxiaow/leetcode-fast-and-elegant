/*从最后开始累加，忽略-，在取余为k+1  */
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret;
        for(auto i=S.rbegin();i<S.rend();i++)
        {
            if(*i!='-')
            {
                if(ret.size()%(K+1)==K)
                    ret+='-';
                ret+=toupper(*i);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};