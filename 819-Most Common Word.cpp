//istringstream
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>ban(banned.begin(),banned.end());
        unordered_map<string,int>count;
        for(auto &c:paragraph) 
            c=isalpha(c)?tolower(c):' ';
        istringstream iss(paragraph);
        string w;
        string res;
        int max_count=0;
        while(iss>>w)
        {
           ++count[w];
        }
        for(auto b:banned)
            count[b]=0;
        for(auto c:count)
        {
            if(c.second>max_count)
            {
                max_count=c.second;
                res=c.first;
            }
                
        }
        return res;
    }
};