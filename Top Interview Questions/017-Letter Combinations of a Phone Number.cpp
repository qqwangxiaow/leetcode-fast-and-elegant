//pay attention to digits.empty ret=[""];
//pool[i] to get how many size to backtracking
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string>mymap({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
        vector<string>pool;
        vector<string>ret;
        string tmp="";
        if(digits.empty())
            return ret;
        for(auto each:mymap)
        {
            pool.push_back(each.second);
        }
        helper(ret,pool,tmp,digits,0);
        return ret;  
    }
    void helper(vector<string>&ret,vector<string>&pool,string &tmp,string &digits,int start)
    {
        if(tmp.size()==digits.size())
        {
            ret.push_back(tmp);
            return;
        }
        for(int i=start;i<digits.size();i++)
        {
            for(int j=0;j<pool[digits[i]-'2'].size();j++)
            {
                tmp.push_back(pool[digits[i]-'2'][j]);
                helper(ret,pool,tmp,digits,i+1);
                tmp.pop_back();
            }
        }
    }
    
}; 