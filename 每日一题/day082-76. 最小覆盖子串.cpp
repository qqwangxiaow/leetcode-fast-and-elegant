//这题真不难啊 while(count==0)
//if(myvec[s[start]>0)表示回复过来了
class Solution {
public:
    string minWindow(string s, string t) {
        int maxlen=INT_MAX;
        int l=0;
        int start=0,end=0;
        vector<int>myvec(256,0);
        int count=0;
        for(auto ch:t)
        {
            myvec[ch]++;
            count++;
        }   
        while(end<s.size())
        {
            if(myvec[s[end]]>0)
            {
                count--;
            }
            myvec[s[end]]--;
            end++;
            while(count==0)
            {
                if(end-start<maxlen)
                {
                    l=start;
                    maxlen=end-start;
                }
                myvec[s[start]]++;
                if(myvec[s[start]]>0)
                    count++;
                start++;
            }
            
        }
        return maxlen==INT_MAX?"":s.substr(l,maxlen);
    }
};