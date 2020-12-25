class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret=0;
        if(s.size()==0)
            return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int l1=0;
        int l2=0;
        while(l1<g.size()&&l2<s.size())
        {
            if(g[l1]<=s[l2])
            {
                ret++;
                l1++;
                l2++;
            }
            else if(g[l1]>s[l2])
            {
                l2++;
            }
        }
        return ret;    
    }
};