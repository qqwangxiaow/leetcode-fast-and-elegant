class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mymap;
        for(auto ch:s)
        {
            mymap[ch]++;
        }
        int ret=0;
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            ret+=it->second/2*2;
        }
        return ret<s.size()?ret+1:ret;
    }
};