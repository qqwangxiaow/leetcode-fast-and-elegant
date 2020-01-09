//map<string,vector<string>>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mymap;
        for(auto str:strs)
        {
            string t=str;
            sort(str.begin(),str.end());
            mymap[str].push_back(t);
        }
        vector<vector<string>>ret;
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            ret.push_back(it->second);
        }
        return ret;
    }
};