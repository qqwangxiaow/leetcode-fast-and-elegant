//count return 0 or 1,so don't use count
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mymap;
        int last=0,start=0,ret=0;
        while(last<s.size())
        {
            while(mymap[s[last]]>0)
            {
                mymap[s[start]]--;
                start++;
            }
            mymap[s[last]]++;
            last++;
            ret=max(ret,last-start);
        }
        return ret;
    }
};