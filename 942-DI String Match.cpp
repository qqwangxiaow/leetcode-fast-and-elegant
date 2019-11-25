//straight forward
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int left=count(S.begin(),S.end(),'D'),right=left;
        vector<int>ret{left};
        for(char &c:S)
        {
            ret.push_back(c=='I'?++right:--left);
        }
        return ret;
    }
};