class Solution {
public:
    vector<int> printNumbers(int n) {
        int count=0;
        vector<int>ret;
        while(n--)
        {
            count=count*10+9;
        }
        for(int i=1;i<=count;i++)
        {
            ret.push_back(i);
        }
        return ret;
    }
};