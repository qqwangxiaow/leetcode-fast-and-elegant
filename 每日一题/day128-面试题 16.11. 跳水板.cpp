class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        set<int>myset;
        for(int i=0;i<=k;i++)
        {
            myset.insert(shorter*i+longer*(k-i));
        }
        vector<int>ret;
        for(auto s:myset)
        {
            if(s)
                 ret.push_back(s);
        }
        //sort(ret.begin(),ret.end());
        return ret;
    
    }
};