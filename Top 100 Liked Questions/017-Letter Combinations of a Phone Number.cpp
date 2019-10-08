//interative
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ret;
        if(digits.empty())
            return {};
        ret.push_back("");
        vector<string>dig{"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++)
        {
            int num=digits[i]-'0';
            if(num<2||num>9)
                continue;
            int len=dig[num-1].size();
            vector<string>tmp;
            for(int j=0;j<len;j++)
            {
                for(int k=0;k<ret.size();k++)
                {
                    tmp.push_back(ret[k]+dig[num-1][j]);
                }  
            }
            ret.swap(tmp);
        }
        return ret;
    }
};
//backtrack
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string>ret;
        unordered_map<char,string>hash;
        hash['2']="abc";
        hash['3']="def";
        hash['4']="ghi";
        hash['5']="jkl";
        hash['6']="mno";
        hash['7']="pqrs";
        hash['8']="tuv";
        hash['9']="wxyz";
        vector<string>pool;
        for(char c:digits)
        {
            pool.push_back(hash[c]);
        }
        hash.clear();
        string local="";
        BackTracking(digits,ret,pool,local);
        return ret;
       
    }
    void BackTracking(string &digits,vector<string>&ret,vector<string>&pool,string &local)
    {
        if(local.size()==digits.size())
        {
            ret.push_back(local);
            return;
        }
        string searchSpace=pool[local.size()];
        for(char s:searchSpace)
        {
            local.push_back(s);
            BackTracking(digits,ret,pool,local);
            local.pop_back();
        }
    }
};