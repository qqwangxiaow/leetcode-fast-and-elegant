//set赋值方式比较先进
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char>myset(J.begin(),J.end());
        int ret=0;
        for(auto ch:S)
        {
            if(myset.count(ch))
                ret++;
        }
        return ret;
    }
};