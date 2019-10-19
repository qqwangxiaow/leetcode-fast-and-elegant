//backtrack 
//分情况 大小写转换
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>ret;
        helper(ret,S,0);
        return ret;
        
    }
    void helper(vector<string>&ret,string &S,int start)
    {
        if(start==S.size())
        {
            ret.push_back(S);
            return ;
        }
        char c=S[start];
        helper(ret,S,start+1);
        if(isalpha(c))
        {
            S[start]=islower(c)?toupper(c):tolower(c);
            helper(ret,S,start+1);
        }
    }
};