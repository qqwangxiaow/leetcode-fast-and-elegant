//&别忘了
//map记忆剩余s的构成情况
//返回结果是空的情况下代表到最后了，那么不用加空格
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>>mymap;
        return helper(s,wordDict,mymap);
        
    }
    vector<string> helper(string s,vector<string>&wordDict,unordered_map<string,vector<string>>&mymap)
    {
        if(mymap.count(s))
            return mymap[s];
        if(s.empty())
            return {""};
        vector<string>ret;
        for(auto word:wordDict)
        {
            if(s.substr(0,word.size())==word)
            {
                vector<string>res=helper(s.substr(word.size()),wordDict,mymap);
                for(auto one:res)
                {
                    ret.push_back(word+(one.empty()?"":" ")+one);
                }
            }
        }
        return mymap[s]=ret;
    }
};