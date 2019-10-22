//map  string to vector<string>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mymap;
        for(string s:strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            mymap[t].push_back(s);
        }
        vector<vector<string>>anagrams;
        for(auto each:mymap)
        {
            anagrams.push_back(each.second);
        }
        return anagrams;
        
    }
};