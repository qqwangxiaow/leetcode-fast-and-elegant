//slide window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>myset;
        int left=0,maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            while(myset.find(s[i])!=myset.end())
            {
                myset.erase(s[left]);
                left++;
            }
            myset.insert(s[i]);
            maxlen=max(maxlen,i-left+1);
        }
        return maxlen;  
    }
};