//& is important
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mymap;
        for(int i=0;i<order.size();i++)
        {
            mymap[order[i]]=i;
        }
        for(auto &word:words)
        {
            for(auto &c:word)
            {
                c=mymap[c];
            }
        }
        return is_sorted(words.begin(),words.end());
    }
};