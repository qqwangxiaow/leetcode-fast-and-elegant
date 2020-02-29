//map
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int>mymap;
        for(auto e:s)
        {
            mymap[e]++;
        }
        for(auto e:s)
        {
            if(mymap[e]==1)
                return e;
        }
        return ' ';
    }
};