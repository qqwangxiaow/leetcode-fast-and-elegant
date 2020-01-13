//sort and 3 situations
//1.merge 2.ignore 3.insert
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ret;
        if(intervals.empty())
            return ret;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        ret.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=ret[ret.size()-1][1]&&intervals[i][1]>ret[ret.size()-1][1])
            {
                int left=ret[ret.size()-1][0];
                ret.pop_back();
                ret.push_back({left,intervals[i][1]});
            }
            else if(intervals[i][1]<=ret[ret.size()-1][1])
                continue;
            else 
                ret.push_back(intervals[i]);
        }
        return ret;
    }
};