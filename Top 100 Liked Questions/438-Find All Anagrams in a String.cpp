//slide window
//pv==sv to compare two vector
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pv(26,0),sv(26,0),ret;
        if(s.size()<p.size())
            return ret;
        for(int i=0;i<p.size();++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv==sv)
            ret.push_back(0);
        for(int i=p.size();i<s.size();++i)
        {
            ++sv[s[i]-'a'];
            --sv[s[i-p.size()]-'a'];
            if(pv==sv)
                ret.push_back(i-p.size()+1);
        }
        return ret;
    }
};