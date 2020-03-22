class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        if(strs.size()==1)
            return strs[0];
        for(int i=0;i<strs[0].size();i++)
        {
            int ch=strs[0][i];
            for(auto str:strs)
            {
                if(str[i]!=ch)
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
        
        
    }
};