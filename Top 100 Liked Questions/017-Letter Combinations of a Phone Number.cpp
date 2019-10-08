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