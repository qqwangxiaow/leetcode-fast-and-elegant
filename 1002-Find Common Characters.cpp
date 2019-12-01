//using two vector
//string(int n,char c); //用n个字符c初始化
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>cnt(26,INT_MAX);
        vector<string>ret;
        for(auto s:A)
        {
            vector<int>cnt1(26,0);
            for(auto c:s)
            {
                cnt1[c-'a']++;
            }
            for(auto i=0;i<26;i++)
            {
                cnt[i]=min(cnt[i],cnt1[i]);
            }
        }
        for(auto i=0;i<26;i++)
        {
            for(auto j=0;j<cnt[i];j++)
                ret.push_back(string(1,i+'a'));
        }
        return ret;
    }
};