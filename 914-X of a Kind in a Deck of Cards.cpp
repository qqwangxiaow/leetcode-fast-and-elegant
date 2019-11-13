//map and gcd   std::gcd is ok too
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mymap;
        for(int i:deck)
            mymap[i]++;
        int res=0;
        for(auto each:mymap)
        {
            res=__gcd(each.second,res);
        }
        return res>1;
    }
};