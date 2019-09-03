/*別忘記初始化 */
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ret(numRows,"");
        int i=0,n=s.size();
        while(i<n)
        {
            for(int j=0;j<numRows&&i<n;j++)
            {
                ret[j]+=s[i++];
            }
            for(int j=numRows-2;j>0&&i<n;j--)
            {
                ret[j]+=s[i++];
            }
        }
        string res;
        for(auto s:ret)
            res+=s;
        return res;
        
    }
};