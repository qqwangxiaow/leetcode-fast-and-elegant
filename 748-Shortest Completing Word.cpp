//用vector当map好些
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int>mymap(26,0);
        int sum=0;
        for(auto ch:licensePlate)
        {
            if(isalpha(ch))
            {
                ++mymap[tolower(ch)-'a'];
            }
            
        }
        int minL=INT_MAX;
        string ret;
        for(auto word:words)
        {
            vector<int>cnt(26,0);
            for(auto ch:word)
            {
                ++cnt[ch-'a'];
            }
            bool compare=true;
            for(int i=0;i<26;i++)
            {
                if(cnt[i]<mymap[i])
                {
                    compare=false;
                    break;
                }
            }
            if(compare&&word.size()<minL)
            {
                ret=word;
                minL=word.size();
            }
        }
        return ret;
            
    }
};