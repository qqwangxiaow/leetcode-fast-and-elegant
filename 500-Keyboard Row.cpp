/*三组分别表示一位（001，010，100），用7（111）对每个字母进行&，为0则代表有不全在一列*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int>dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        vector<string>ret;
        for(int i=0;i<rows.size();i++)
        {
            for(auto c:rows[i])
            {
                dict[c-'A']=1<<i;
            }
        }
        for(auto each:words)
        {
            int r=7;
            for(auto c:each)
            {
                r=r&dict[toupper(c)-'A']; 
            }
            if(r!=0)
                ret.push_back(each);
        }
        return ret;
    }
};