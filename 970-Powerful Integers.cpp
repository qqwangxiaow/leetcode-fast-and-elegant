//brute force 
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>myset;
        for(int i=1;i<=bound;i*=x)
        {
            for(int j=1;i+j<=bound;j*=y)
            {
                myset.insert(i+j);
                if(y==1)
                    break;
            }
            if(x==1)
                break;
        }
        vector<int>ret(myset.begin(),myset.end());
        return ret;

    }
};