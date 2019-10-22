//set
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char>myset(J.begin(),J.end());
        int ret=0;
        for(int i=0;i<S.size();i++)
        {
            if(myset.count(S[i]))
                ret++;
        }
        return ret;
    }
};