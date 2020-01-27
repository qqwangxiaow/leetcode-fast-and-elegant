//push
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ret;
        for(int i=0;i<numRows;i++)
        {
            if(i==0)
            {
                ret.push_back({1});
                continue;
            }
            if(i==1)
            {
                ret.push_back({1,1});
                continue;
            }
            ret.push_back({1});
            for(int j=0;j<ret[i-1].size()-1;j++)
            {
                ret.back().push_back(ret[i-1][j]+ret[i-1][j+1]);
            }
            ret.back().push_back(1);
        }
        return ret;
    }
};