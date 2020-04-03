//backtrack
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ret;
        if(digits.empty())
            return ret;
        string temp="";
        helper(ret,digits,temp,0);
        return ret; 
    }
    void helper(vector<string>&ret,string &digits,string temp,int start)
    {
        if(start==digits.size())
        {
            ret.push_back(temp);
            return;
        }
        for(int i=0;i<mymap[digits[start]].size();i++)
        {
            temp+=mymap[digits[start]][i];
            helper(ret,digits,temp,start+1);
            temp.pop_back();
        }

    }
private:
    map<char, string>mymap= {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};