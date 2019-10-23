//map substr to_string
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mymap;
        vector<string>ret;
        for(auto cd:cpdomains)
        {
            int i=cd.find(" ");
            int n=stoi(cd.substr(0,i));
            string s=cd.substr(i+1);
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='.')
                    mymap[s.substr(i+1)]+=n;
            }
            mymap[s]+=n;
        }
        for(auto each:mymap)
        {
            ret.push_back(to_string(each.second)+" "+each.first);
        }
        return ret;
        
    }
};