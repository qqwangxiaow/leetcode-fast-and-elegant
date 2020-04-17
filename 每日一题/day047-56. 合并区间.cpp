//sort lambda
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&v1,const vector<int>&v2){
            return v1[0]<v2[0]||(v1[0]==v2[0]&&v1[1]<v2[1]);
        });
        vector<vector<int>>ret;
        for(auto interval:intervals)
        {
            if(ret.empty())
                ret.push_back(interval);
            else
            {
                if(interval[0]<=ret.back()[1]&&interval[1]>ret.back()[1])
                    ret.back()[1]=interval[1];
                else if(interval[0]>ret.back()[1])
                    ret.push_back(interval);
            }
        }
        return ret;

    }
};