//!flag 应该for循环结束后
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ret;
        int left=newInterval[0],right=newInterval[1];
        int flag=0;
        for(const auto &interval:intervals)
        {
            if(interval[0]>right)
            {
                if(!flag)
                {
                    ret.push_back({left,right});
                    flag=1;   
                }
                ret.push_back(interval);
            }
            else if(interval[1]<left)
                ret.push_back(interval);
            else
            {
                left=min(interval[0],left);
                right=max(interval[1],right);
            }  
        }
        if(!flag)
            ret.push_back({left,right});
        return ret;
    }
};

