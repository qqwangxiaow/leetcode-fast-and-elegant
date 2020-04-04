//连续两个括号深度会变多
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ret(seq.size(),0);
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                ret[i]=(i&1);
            }
            else
            {
                ret[i]=(i+1)&1;
            }
        }
        return ret;
    }
};