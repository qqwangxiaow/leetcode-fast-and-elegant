//count
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>cnt(26,INT_MAX);
        for(auto s:A)
        {
            vector<int>cnt1(26,0);
            for(auto ch:s)
            {
                cnt1[ch-'a']++;
            }
            for(int i=0;i<cnt.size();i++)
            {
                cnt[i]=min(cnt[i],cnt1[i]);
            }
        }
        vector<string>ret;
        for(int i=0;i<cnt.size();i++)
        {
            if(cnt[i]!=INT_MAX)
            {
                for(int j=0;j<cnt[i];j++)
                {
                    ret.push_back(string(1,'a'+i));
                }
            }
        }
        return ret;
    }
};