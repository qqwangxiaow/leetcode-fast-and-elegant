//
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>>m;
        return helper(s,wordDict,m);
    }
    vector<string> helper(string s,vector<string>&wordDict,unordered_map<string,vector<string>>&m)
    {
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};
        vector<string>res;
        for(auto each:wordDict)
        {
            if(s.substr(0,each.size())==each)
            {
             vector<string>rem=helper(s.substr(each.size()),wordDict,m);
             for(auto str:rem)
             {
                 res.push_back(each+(str.empty()?"":" ")+str);
             }
            }   
                
        }
        return m[s]=res; 
    }
    
};

//回溯超时
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>myset(wordDict.begin(),wordDict.end());
        vector<string>ret;
        vector<string>tmp;
        helper(ret,s,tmp,myset,0);
        return ret;
    }
    void helper(vector<string>&ret,string &s,vector<string>&tmp,unordered_set<string>&myset,int start)
    {
        if(start==s.size())
        {
            string temp="";
            for(auto str:tmp)
            {
                if(temp=="")
                {
                    temp+=str;
                }
                else
                {
                    temp+=" ";
                    temp+=str;
                }
            }
            ret.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            if(myset.count(s.substr(start,i-start+1)))
            {
                tmp.push_back(s.substr(start,i-start+1));
                helper(ret,s,tmp,myset,i+1);
                tmp.pop_back();
            }
        }
    }
};