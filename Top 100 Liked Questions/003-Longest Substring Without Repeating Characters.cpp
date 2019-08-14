/*slide window 用dict表示位置 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int l=0,maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            if(dict[s[i]]==-1||dict[s[i]]<l)
            {
                maxlen=max(maxlen,i-l+1);
            }
            else
            {
                l=dict[s[i]];
            }
            dict[s[i]]=i+1;
            
        }
        return maxlen;
        
        
            
        
    }
};