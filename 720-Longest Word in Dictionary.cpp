//sort and iteration
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string ret;
        unordered_set<string>myset;
        for(auto word:words)
        {
            if(word.size()==1||myset.count(word.substr(0,word.size()-1)))
            {
                ret=word.size()>ret.size()?word:ret;
                myset.insert(word);
            }
        }
        return ret;
        
    }
};