//using map keep index more faster
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int start=0,maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            if(dict[s[i]]==-1||dict[s[i]]<start)
            {
                maxlen=max(maxlen,i-start+1);
            }
            else
            {
                start=dict[s[i]]+1;
            }
            dict[s[i]]=i;
        }
        return maxlen;
    }
};
//using set;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>myset;
        int start=0,end=0,d=0;
        while(end<s.size())
        {
            while(myset.find(s[end])!=myset.end())
            {
                myset.erase(s[start++]);
            }
            myset.insert(s[end++]);
            d=max(d,static_cast<int>(myset.size()));
        }
        return d;
    }
};