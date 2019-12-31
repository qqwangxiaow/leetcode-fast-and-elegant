//遍历第一个字符串 逐个字符加入 越界或不等返回
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret="";
        if(strs.empty()) return ret;
        if(strs.size()==1) return strs[0];
        for(int i=0;i<strs[0].size();i++)
        {
            char tmp=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(i>=strs[j].size()||strs[j][i]!=tmp)
                    return ret;
            }
            ret.push_back(tmp);
        }
        return ret; 
    }
};
