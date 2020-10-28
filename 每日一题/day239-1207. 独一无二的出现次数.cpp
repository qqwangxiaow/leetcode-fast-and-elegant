//easy
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mymap;
        for(auto one:arr)
        {
            mymap[one]++;
        }
        set<int>myset;
        for(auto it:mymap)
        {
            if(myset.count(it.second))
                return false;
            myset.insert(it.second);
        }
        return true;
    }
};